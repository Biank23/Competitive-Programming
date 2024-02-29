#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
vector<ll> getSums(vector<int> &v) {
    int n = ssize(v);
    vector<ll> dp(1<<n, 0);
    for (int mask = 1; mask < 1<<n; mask++) {
        int bit = __builtin_ctz(mask);
        dp[mask] = dp[mask^(1<<bit)] + v[bit];
    }
    return dp;
}
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, target;
    cin >> n >> target;
    
    vector<int> v[2];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i&1].push_back(x);
    }
    
    ll res = 0;
    vector<ll> sums = getSums(v[0]);
    sort(all(sums));
    for (ll x : getSums(v[1])) {
        res += upper_bound(all(sums), target - x) - lower_bound(all(sums), target - x);
    }
    cout << res << '\n';
    
    return 0;
}
