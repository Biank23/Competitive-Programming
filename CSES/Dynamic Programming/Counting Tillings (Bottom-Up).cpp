#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 10;
const int MOD = 1e9 + 7;
 
int dp[2][1<<MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int t = 0;
    dp[t][0] = 1;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            t ^= 1;
            for (int mask = 0; mask < 1<<n; mask++) {
                dp[t][mask] = dp[t ^ 1][mask ^ (1<<i)];
                if (i != 0 && !(mask>>i&1) && !(mask>>(i-1)&1)) {
                    dp[t][mask] += dp[t ^ 1][mask^(1<<(i-1))];
                    if (dp[t][mask] >= MOD) {
                        dp[t][mask] -= MOD;
                    }
                }
            }
        }
    }
    
    cout << dp[t][0] << '\n';
    
    return 0;
}