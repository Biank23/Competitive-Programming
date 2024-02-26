#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_K = 20;
 
ll a[MAX_K], dp[1<<MAX_K];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }    
    
    ll res = 0;
    dp[0] = n;
    for (int mask = 1; mask < 1<<k; mask++) {
        int bit = __builtin_ctz(mask);
        dp[mask] = dp[mask^(1<<bit)] / a[bit];
        if (__builtin_parity(mask)) res += dp[mask];
        else res -= dp[mask];
    }
    cout << res << '\n';
    
    return 0;
}