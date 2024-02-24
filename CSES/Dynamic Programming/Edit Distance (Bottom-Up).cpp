#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 5005;
const int INF = 1e9;
 
int dp[MAX_N][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string a, b;
    cin >> a >> b;
    int n = ssize(a);
    int m = ssize(b);
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) continue;
            dp[i][j] = INF;
            if (i != 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j != 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (i != 0 && j != 0) {
                int cost = (a[i - 1] != b[j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost);
            }
        }
    }
    cout << dp[n][m] << '\n';
    
    return 0;
}