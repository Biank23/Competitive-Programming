#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vb = vector<bool>;

vector<vb> rotate(vector<vb> &g) {
    int n = sz(g), m = sz(g[0]);
    for (int i = 0; i < n; i++) {
        reverse(all(g[i]));
    }
    vector<vb> t(m, vb(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[j][i] = g[i][j];
        }
    }
    return t;
}

pair<vi, vii> calc(vector<vb> &g) {
    int n = sz(g), m = sz(g[0]);
    vi dp(n, 0);
    vii idx(n);
    vi h(m, 0), l(m), r(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) h[j]++;
            else h[j] = 0;
        }
        for (int j = 0; j < m; j++) {
            l[j] = j - 1;
            while (l[j] != -1 && h[l[j]] >= h[j]) {
                l[j] = l[l[j]];
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            r[j] = j + 1;
            while (r[j] != m && h[r[j]] >= h[j]) {
                r[j] = r[r[j]];
            }
        }
        for (int j = 0; j < m; j++) {
            int side = min(h[j], r[j] - l[j] - 1);
            if (side > dp[i]) {
                dp[i] = side;
                idx[i] = {i - side + 1, l[j] + 1};
            }
        }
        if (i > 0 && dp[i - 1] > dp[i]) {
            dp[i] = dp[i - 1];
            idx[i] = idx[i - 1];
        }
    }
    return {dp, idx};
}

int main() {
    freopen("aventureros.in", "r", stdin);
    freopen("aventureros.out", "w", stdout);
    
    int n, m, c;
    cin >> n >> m >> c;
    vector<vb> g(n, vb(m, true));
    for (int i = 0; i < c; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x][y] = false;
    }
    const int ROT = 4;
    vi dp[ROT];
    vii idx [ROT];
    for (int i = 0; i < ROT; i++) {
        tie(dp[i], idx[i]) = calc(g);
        g = rotate(g);
    }
    int ans = 0;
    ii place = {0, 0};
    for (int j = 0; j < 2; j++) {
        int s = sz(dp[j]);
        for (int i = 0; i < s - 1; i++) {
            int area = dp[j][i] * dp[j][i] + dp[j + 2][s - i - 2] * dp[j + 2][s - i - 2];
            if (area > ans) {
                ans = area;
                place = {j, i};
            }
        }
    }
    auto [j, i] = place;
    int s = sz(dp[j]);
    auto [x1, y1] = idx[j][i];
    auto [x2, y2] = idx[j + 2][s - i - 2];
    int s1 = dp[j][i], s2 = dp[j + 2][s - i - 2];
    if (j == 0) {
        cout << x1 << ' ' << y1 << ' ' << s1 << '\n';
        cout << n - x2 - s2 << ' ' << m - y2 - s2 << ' ' << s2 << '\n';
    } else {
        cout << y1 << ' ' << m - x1 - s1 << ' ' << s1 << '\n';
        cout << n - y2 - s2 << ' ' << x2 << ' ' << s2 << '\n';
    }

    return 0;
}