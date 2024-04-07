#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6e4 + 9;
const int MAX_K = 305;
const int INF = 1e9;

int dp[MAX_N][MAX_K];

int main() {
    freopen("pajaros.in", "r", stdin);
	freopen("pajaros.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < MAX_K; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < MAX_K; j++) {
            int cost = abs(a - j);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost);
            if (j + 1 < MAX_K) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + cost);
        }
    }
    int ans = INF;
    for (int j = 0; j < MAX_K; j++) {
        ans = min(ans, dp[n][j]);
    }
    cout << ans << '\n';
    
    return 0;
}
