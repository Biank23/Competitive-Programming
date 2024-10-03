#include <bits/stdc++.h>
 
using namespace std;
 
struct STree {
    int n;
    vector<bool> st;
    STree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        st.assign(2 * n, false);
        for (int i = 0; i < _n; i++) {
            st[n + i] = true;
        }
        for (int i = n - 1; i > 0; i--) {
            st[i] = st[2 * i] || st[2 * i + 1];
        }
    }
    void update(int p) {
        st[p += n] = false;
        while (p /= 2) st[p] = st[2 * p] || st[2 * p + 1];
    }
    int find(int u) {
        while (u < n) {
            u *= 2;
            if (!st[u]) u++;
        }
        return u - n;
    }
    int lower_bound(int x) {
        int l = x + n, r = 2 * n;
        int u = -1;
        while (l < r) {
            if (l & 1) {
                if (st[l]) return find(l);
                l++;
            }
            if (r & 1) {
                r--;
                if (st[r]) u = r;
            }
            l /= 2, r /= 2;
        }
        if (u == -1) return n;
        return find(u);
    }
};
 
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int h, w, k, s_r, s_c, g_r, g_c;
    cin >> h >> w >> k >> s_r >> s_c >> g_r >> g_c;
    --s_r, --s_c, --g_r, --g_c;
    vector<string> g(h);
    for (int i = 0; i < h; i++) cin >> g[i];
    
    vector<STree> row(h, STree(w));
    vector<STree> col(w, STree(h));
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    vector<vector<int>> dist(h, vector<int>(w, 0));
    deque<tuple<int, int, int>> dq;
    const auto push = [&](int x, int y) {
        assert(!vis[x][y]);
        dq.emplace_front(x, y, 0);
        vis[x][y] = true;
        row[x].update(y);
        col[y].update(x);
    };
    push(s_r, s_c);
    const auto push_row = [&](int x, int l, int r, int d) {
        l = max(l, 0), r = min(r, w);
        while (true) {
            int p = row[x].lower_bound(l);
            if (p < r) {
                dist[x][p] = d;
                push(x, p);
            } else break;
        }
    };
    const auto push_col = [&](int y, int l, int r, int d) {
        l = max(l, 0), r = min(r, h);
        while (true) {
            int p = col[y].lower_bound(l);
            if (p < r) {
                dist[p][y] = d;
                push(p, y);
            } else break;
        }
    };
    while (!dq.empty()) {
        auto [x, y, op] = dq.front();
        dq.pop_front();
        if (op == 0) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && g[nx][ny] == '.') {
                    dist[nx][ny] = dist[x][y];
                    push(nx, ny);
                }
            }
            dq.emplace_back(x, y, 1);
        } else {
            int new_dist = dist[x][y] + 1;
            if (abs(x - g_r) <= k && abs(y - g_c) <= k && abs(x - g_r) + abs(y - g_c) < 2 * k && !vis[g_r][g_c]) {
                dist[g_r][g_c] = new_dist;
                push(g_r, g_c);
            }
            if (x - k >= 0) push_row(x - k, y - k + 1, y + k, new_dist);
            if (x + k < h) push_row(x + k, y - k + 1, y + k, new_dist);
            if (y - k >= 0) push_col(y - k, x - k + 1, x + k, new_dist);
            if (y + k < w) push_col(y + k, x - k + 1, x + k, new_dist);
        }
    }
    cout << dist[g_r][g_c] << '\n';
    
    return 0;
}