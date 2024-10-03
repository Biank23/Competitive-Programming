#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 30;
 
using ll = long long;
 
ll dp[MAX_N][MAX_N][2];
char g[MAX_N][MAX_N];
 
ll ways(int n, int m, string &s) {
    memset(dp, 0, sizeof dp);
    dp[0][0][g[0][0] != s[0]] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != 0) {
                dp[i][j][1] += dp[i - 1][j][1];
                if (g[i][j] <= s[i + j]) {
                    dp[i][j][g[i][j] != s[i + j]] += dp[i - 1][j][0];
                }
            }
            if (j != 0) {
                dp[i][j][1] += dp[i][j - 1][1];
                if (g[i][j] <= s[i + j]) {
                    dp[i][j][g[i][j] != s[i + j]] += dp[i][j - 1][0];
                }
            }
        }
    }
    return dp[n - 1][m - 1][0] + dp[n - 1][m - 1][1];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    ll k;
    cin >> k;
    
    string ans{g[0][0]};
    for (int i = 0; i < n + m - 2; i++) {
        int lo = -1, hi = 25;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            string s = ans + char('a' + mid);
            s.resize(n + m - 1, 'z');
            if (ways(n, m, s) >= k) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        ans += char('a' + hi);
    }
    cout << ans << '\n';
    
    return 0;
}