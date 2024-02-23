#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 20;
 
ll dp[1<<MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> p(n);
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        tot += p[i];
    } 
    
    ll minDiff = tot;
    dp[0] = 0;
    for (int mask = 1; mask < 1<<n; mask++) {
        int i = __builtin_ctz(mask);
        dp[mask] = dp[mask^(1<<i)] + p[i];
        ll sum = dp[mask], otherSum = tot - dp[mask];
        minDiff = min(minDiff, abs(sum - otherSum));
    }
    cout << minDiff << '\n';
    
    return 0;
}
