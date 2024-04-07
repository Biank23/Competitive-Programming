#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int MAX_N = 2e5 + 9;
const int MAX_K = 21;
const int INF = 4e5;

int dp[MAX_N][MAX_K];

int solve(int k, string a, string b) {
    int n = sz(a), m = sz(b);
    if (m - n > k) return INF;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_K; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = k; i <= 2 * k; i++) {
        dp[0][i] = i - k;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * k; j++) {
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (j < 2 * k) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + 1);
            }
            int p = i + j - k;
            if (0 < p && p <= m) {
                int c = a[i - 1] != b[p - 1];
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + c);
            }
        }
    }
    return dp[n][m - n + k];
}

int main() {
    freopen("adn.in", "r", stdin);
    freopen("adn.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    string a, b;
    cin >> n >> m >> k >> a >> b;
    if (n > m) swap(a,b);
    int ans = solve(k, a, b);
    if (ans > k) cout << "Muy distintas.\n";
    else cout << ans << '\n';
    
    return 0;
}
