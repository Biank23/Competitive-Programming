#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;
const int INF = 1e9;

string g[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (g[i][0] == 'A') dp[i][0] = 0;
        else dp[i][0] = -INF;
    }
    
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int best = dp[i][j - 1];
            if (i > 0) best = max(best, dp[i - 1][j - 1]);
            if (i < n - 1) best = max(best, dp[i + 1][j - 1]);
            if (g[i][j] == 'M') {
                if (best > 0) dp[i][j] = 0;
                else dp[i][j] = -INF;
            } else {
                dp[i][j] = best + (g[i][j] == 'J');
            }
        }
    }
    
    int ans = -INF;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i][m - 1]);
    }
    if (ans < 0) cout << "SIN SALIDA\n";
    else cout << ans << '\n';
    
    return 0;
}
