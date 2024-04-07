#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int w, h, n;
    cin >> w >> h >> n;
    vector<vector<int>> dp(w + 1, vector<int>(h + 1));
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            dp[i][j] = i * j;
        }
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 0;
    }
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);;
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
    }
    cout << dp[w][h] << '\n';
    
    return 0;
}
