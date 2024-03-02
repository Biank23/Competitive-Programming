#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 500;
const int MAX_K = MAX_N * (MAX_N - 1) / 2 + 1;
const int MOD = 1e9 + 7;
 
int dp[MAX_K], pref[MAX_K];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            pref[j] = dp[j];
            if (j > 0) {
                pref[j] += pref[j - 1];
                if (pref[j] >= MOD) pref[j] -= MOD;
            }
        }
        for (int j = 0; j <= k; j++) {
            dp[j] = pref[j];
            if (j >= n - i) {
                dp[j] -= pref[j - n + i];
                if (dp[j] < 0) dp[j] += MOD;
            }
        }
    }
    
    cout << dp[k] << '\n';
    
    return 0;
}