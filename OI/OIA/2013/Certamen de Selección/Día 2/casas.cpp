#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int, int>;

const int INF = 1e9;

int main() {
    freopen("casas.in", "r", stdin);
	freopen("casas.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> p(n + 1);
    p[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<vector<int>> par(n + 1, vector<int>(x / 2 + 1));
    vector<ii> prev{{-INF, -1}, {0, 0}};
    for (int i = 1; i <= n; i++) {
        vector<ii> curr{{-INF, -1}};
        for (int j = 1; 2 * j <= x && p[i] + j <= y && p[i] >= j; j++) {
            int pos = p[i] - p[i - 1] - j;
            if (pos < 0) pos = 0;
            if (pos >= sz(prev)) pos = sz(prev) - 1; 
            auto [val, k] = prev[pos];
            curr.emplace_back(val + 4 * j * j, p[i] + j);
            par[i][j] = k;
        }
        for (int j = 0; j < sz(curr) - 1; j++) {
            if (curr[j].first > curr[j + 1].first) {
                curr[j + 1] = curr[j];
            }
        }
        prev = curr;
    }
    ii ans = prev.back();
    cout << ans.first << '\n';
    vector<int> v(n);
    int j = ans.second - p[n];
    for (int i = n - 1; i >= 0; i--) {
        v[i] = 2 * j;
        j = par[i + 1][j] - p[i];
    }
    for (int h : v) {
        cout << h << '\n';
    }
    
    return 0;
}
