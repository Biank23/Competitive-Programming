#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x),end(x)
 
const int INF = 2e9;
 
int solve(vector<vector<int>> &a) {
    int n = sz(a), m = sz(a[0]);
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -a[i][j] + i + j - 1;
            if (i != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j != 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    int ans = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, a[i][j] - i - j + dp[i][j]);
        }
    }
    return ans;
}
 
vector<vector<int>> transpose(vector<vector<int>> &a) {
    int n = sz(a), m = sz(a[0]);
    vector<vector<int>> t(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[j][i] = a[i][j];
        }
    }
    return t;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = -INF;
    int r = 4;
    while (r--) {
        a = transpose(a), swap(n, m);
        for (int i = 0; i < n; i++) {
            reverse(all(a[i]));
        }
        ans = max(ans, solve(a));
    }
    cout << ans << '\n';
    
    return 0;
}