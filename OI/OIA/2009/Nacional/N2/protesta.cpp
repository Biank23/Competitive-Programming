#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1009;

#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

using ii = pair<int, int>;

bitset<MAX_N> g[MAX_N];
ii par[MAX_N][MAX_N][2];
int dist[MAX_N][MAX_N][2];

ii getPos(int a, int b) {
    if (a % 2 == 1) swap(a, b);
    return {a / 2 - 1, b / 2};
}

using State = pair<ii, int>;

const int INF = 1e9;

const ii movesX[2] = {{0, -1}, {0, 1}};
const ii movesY[2] = {{-1, 0}, {1, 0}};

int main() {
    freopen("protesta.in", "r", stdin);
	freopen("protesta.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, a, b, c, d, m;
    cin >> n >> a >> b >> c >> d >> m;
    ii start = getPos(a, b), end = getPos(c, d);
    for (int i = 0; i < m; i++) {
        int h, v;
        cin >> h >> v;
        auto [x, y] = getPos(h, v);
        g[x][y] = 1;
    }
    const int MAX_X = n / 2;
    const int MAX_Y = (n + 1) / 2;
    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            dist[i][j][0] = dist[i][j][1] = INF;
        }
    }
    deque<State> dq;
    for (int i = 0; i < 2; i++) {
        dq.emplace_front(start, i);
        auto [x, y] = start;
        par[x][y][i] = {-1, -1};
        dist[x][y][i] = 0;
    }
    while (!dq.empty()) {
        auto [pos, dir] = dq.front();
        auto [x, y] = pos;
        dq.pop_front();
        ii moves[2] = {movesX[x % 2],
                       movesY[y % 2]};
        for (int i = 0; i < 2; i++) {
            auto [dx, dy] = moves[i];
            int nx = x + dx, ny = y + dy;
            ii npos = {nx, ny};
            if (0 <= nx && nx < MAX_X && 0 <= ny && ny < MAX_Y && !g[nx][ny]) {
                int ndist = dist[x][y][dir] + (i != dir);
                if (dist[nx][ny][i] > ndist) {
                    dist[nx][ny][i] = ndist;
                    par[nx][ny][i] = {x, y};
                    if (i == dir) dq.emplace_front(npos, i);
                    else dq.emplace_back(npos, i);
                }
            }
        }
    }
    ii pos = end;
    auto &[x, y] = pos;
    auto getDir = [&](int prevDir) {
        if (dist[x][y][0] + (prevDir != 0) < dist[x][y][1] + (prevDir != 1)) {
            return 0;
        } else {
            return 1;
        }
    };
    int dir = getDir(-1);
    if (dist[x][y][dir] == INF) {
        cout << "0\n";
        return 0;
    }
    auto getStreet = [&](int currDir) {
        if (currDir == 0) return 2 * (x + 1);
        if (currDir == 1) return 2 * y + 1;
        assert(false);
    };
    vector<int> path{getStreet(dir)};
    while (pos != ii{-1, -1}) {
        int ndir = getDir(dir);
        pos = par[x][y][ndir];
        if (dir != ndir) path.push_back(getStreet(ndir));
        dir = ndir;
    }
    reverse(all(path));
    cout << "1\n" << sz(path) << '\n';
    for (int street : path) {
        cout << street << '\n';
    }
    
    return 0;
}
