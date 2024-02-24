#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 501;
const int INF = 1e9;
 
int dp[MAX_N][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            
            dp[i][j] = INF;
            for (int k = 1; k <= i / 2; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k <= j / 2; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b] << '\n';
    
    return 0;
}