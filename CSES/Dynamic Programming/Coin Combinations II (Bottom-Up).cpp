#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_X = 1e6 + 9;
const int MAX_N = 100;
 
int dp[MAX_X], c[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j <= x; j++) {
            dp[j] += dp[j - c[i]];
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
    }
    
    cout << dp[x] << '\n';
    
    return 0;
}