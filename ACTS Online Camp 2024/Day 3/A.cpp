#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int, int>;
 
const int MAX_N = 1000;
const int MAX_K = 20;
const int MAX_C = MAX_N * MAX_N;

string g[MAX_N];
int c[MAX_N][MAX_N], D[MAX_N][MAX_N];
auto d = [](ii x) {
    return D[x.first][x.second];
};
int length[MAX_C];
vector<ii> group[MAX_C];
bitset<MAX_N> robot[MAX_N], done[MAX_N], vis[MAX_N];
ii up[MAX_K][MAX_N][MAX_N], pos[MAX_C];

map<char, int> dx = {{'s', 1}, {'n', -1}},
               dy = {{'e', 1}, {'w', -1}};

void dfs(int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = true;
    char dir = g[x][y];
    int nx = x + dx[dir], ny = y + dy[dir];
    up[0][x][y] = {nx, ny};
    dfs(nx, ny);
    D[x][y] = D[nx][ny] + 1;
}

ii jump(ii u, int k) {
    auto &[x, y] = u;
    for (int i = 0; i < MAX_K; i++) {
        if (k >> i & 1) u = up[i][x][y];
    }
    return u;
}

int check(ii u, ii v) {
    int dist = d(u) - d(v);
    if (dist >= 0 && jump(u, dist) == v) return dist;
    return -1;
}

int dist(ii u, ii v) {
    int dist = check(u, v);
    if (dist == -1) dist = d(u) + check(jump(u, d(u)), v);
    assert(dist != -1);
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    bool r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (isupper(g[i][j])) {
                robot[i][j] = true;
                g[i][j] = (char) tolower(g[i][j]);
            }
        }
    }
    int maxColor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (done[i][j]) continue;
            queue<ii> path;
            int x = i, y = j;
            while (!done[x][y]) {
                done[x][y] = true;
                path.emplace(x, y);
                char dir = g[x][y];
                x += dx[dir], y += dy[dir];
            }
            path.emplace(x, y);
            int color = c[x][y];
            if (!color) color = maxColor++;
            while (!path.empty()) {
                if (!length[color] && path.front() == path.back()) {
                    pos[color] = path.front();
                    length[color] = sz(path) - 1;
                }
                tie(x, y) = path.front();
                path.pop();
                c[x][y] = color;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j);
            if (robot[i][j]) {
                group[c[i][j]].emplace_back(i, j);
            }
        }
    }
    for (int k = 1; k < MAX_K; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto [x, y] = up[k - 1][i][j];
                up[k][i][j] = up[k - 1][x][y];
            }
        }
    }
    
    vector<pair<ii, int>> ans;
    for (int i = 1; i < maxColor; i++) {
        int k = min(length[i], sz(group[i]));
        for (int j = 0; j < k; j++) {
            ans.emplace_back(group[i][j], n * m - dist(group[i][j], pos[i]) + j);
        }
    }
    cout << sz(ans) << '\n';
    if (r) {
        for (auto [u, t] : ans) {
            auto [x, y] = u;
            cout << x + 1 << ' ' << y + 1 << ' ' << t << '\n'; 
        }
    }
    
    return 0;
}