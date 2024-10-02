#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
 
const vector<string> IMPOSSIBLE = {};
 
vector<string> solve(int n, int m) {
    if (n % 3 != 0) return IMPOSSIBLE;
    if (m == 1) return IMPOSSIBLE;
    vector<string> ans(n, string(m, '.'));
    auto fillPattern = [&](int s_i, int s_j, const vector<vector<int>> &pattern, const string &palette) {
        for (int i = 0; i < sz(pattern); i++) {
            for (int j = 0; j < sz(pattern[i]); j++) {
                ans[s_i + i][s_j + j] = palette[pattern[i][j]];
            }
        }
    };
    const vector<vector<int>> pattern_3_2 = {{0, 0},
                                             {0, 1},
                                             {1, 1}};
    const vector<vector<int>> pattern_2_3 = {{0, 0, 1},
                                             {0, 1, 1}};
    const vector<vector<int>> pattern_9_5 = {{0, 0, 1, 0, 0},
                                             {0, 2, 1, 1, 0},
                                             {3, 2, 2, 3, 3},
                                             {3, 3, 1, 0, 3},
                                             {0, 1, 1, 0, 0},
                                             {0, 0, 2, 2, 1},
                                             {1, 1, 2, 1, 1},
                                             {1, 0, 3, 3, 0},
                                             {0, 0, 3, 0, 0}};
    auto complete = [&](int s_i, int s_j) {
        for (int i = s_i; i < n; i += 3) {
            string s[2] = {"AB", "CD"};
            int k = 0;
            for (int j = s_j; j < m; j += 2) {
                fillPattern(i, j, pattern_3_2, s[k ^= 1]);
            }
        }
    };
    if (m % 2 == 0) {
        complete(0, 0);
    } else if (n % 2 == 0) {
        string s[2] = {"EF", "GH"};
        int j = 0;
        for (int i = 0; i < n; i += 2) {
            fillPattern(i, 0, pattern_2_3, s[j ^= 1]);
        }
        complete(0, 3);
    } else if (m >= 5 && n >= 9) {
        fillPattern(0, 0, pattern_9_5, "EFGH");
        string s[2] = {"IJ", "KL"};
        int j = 0;
        for (int i = 9; i < n; i += 2) {
            fillPattern(i, 0, pattern_2_3, s[j ^= 1]);
        }
        s[0] = "MN", s[1] = "OP";
        for (int i = 9; i < n; i += 3) {
            fillPattern(i, 3, pattern_3_2, s[j ^= 1]);
        }
        complete(0, 5);
    } else return IMPOSSIBLE;
    return ans;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool flag = false;
        int h = n, w = m;
        for (int p = 0; p < 2 && !flag; p++) {
            auto ans = solve(h, w);
            swap(h, w);
            if (ans == IMPOSSIBLE) continue;
            flag = true;
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (p == 0) cout << ans[i][j];
                    else cout << ans[j][i];
                }
                cout << '\n';
            }
        }
        if (!flag) cout << "NO\n";
    }
    
    return 0;
}