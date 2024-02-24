#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 9;
 
int dp[MAX_N]; 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(6, i); j++) {
            dp[i] += dp[i - j];
            if (dp[i] >= MOD) {
                dp[i] -= MOD;
            }
        }
    }
    cout << dp[n] << '\n';
    
    return 0;
}
