#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
#define size(x) (int)x.size()
 
using ll = long long;
 
vector<ll> getSums(const vector<ll> &v) {
    vector<ll> dp(1<<size(v), 0);
    for (int mask = 1; mask < size(dp); mask++) {
        int bit = __builtin_ctz(mask);
        dp[mask] = v[bit] + dp[mask^(1<<bit)];
    }
    sort(all(dp), greater<ll>());
    return dp;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, target;
    cin >> n >> target;
    
    vector<ll> v[2];
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i&1].push_back(x);
    }
    
    ll res = 0;
    vector<ll> sums = getSums(v[0]);
    reverse(all(sums));
    int l = 0, r = 0;
    for (const ll &x : getSums(v[1])) {
        while (l < size(sums) && sums[l] < target - x) l++;
        while (r < size(sums) && sums[r] <= target - x) r++;
        res += r - l;
    }
    cout << res << '\n';
    
    return 0;
}