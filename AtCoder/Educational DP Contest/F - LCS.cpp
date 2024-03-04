#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(x.size())

using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s, t;
    cin >> s >> t;
    
    int n = sz(s), m = sz(t);
    vector<vi> dp(n + 1, vi(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    
    string res = "";
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) {
            res += s[i];
            i--, j--;
            continue;
        }

        if (dp[i + 1][j] > dp[i][j + 1]) {
            j--;
        } else {
            i--;
        }
    }
    reverse(all(res));
    cout << res << '\n';
    
    return 0;
}
