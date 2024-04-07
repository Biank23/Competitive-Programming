#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int MAX_N = 121;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

using ti = tuple<int, int, int>;
const ti UNDEFINED = {-1, -1, -1};
const ti END = {-2, -2, -2};

ti par[MAX_N][MAX_N][MAX_N];
string g[MAX_N];

int main() {
    freopen("tesoro.in", "r", stdin);
	freopen("tesoro.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, f;
    cin >> n >> m >> f;
    queue<ti> q;
    memset(par, -1, sizeof par);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'T') {
                par[i][j][f] = END;
                q.emplace(i, j, f);
            }
        }
    }
    
    ti pos = UNDEFINED;
    while (!q.empty()) {
        ti u = q.front();
        auto [x, y, z] = u;
        q.pop();
        if (x == 0 && y == 0) {
            pos = u;
            break;
        }
        for (int i = 0; i < 4; i++) {
            ti v = u;
            auto &[nx, ny, nz] = v; 
            nx += dx[i], ny += dy[i];
            if (nx < 0 || nx >= n ||
                ny < 0 || ny >= m ||
                g[nx][ny] == 'P') {
                continue;
            }
            nz -= g[nx][ny] == 'W';
            if (nz >= 0 && par[nx][ny][nz] == UNDEFINED) {
                par[nx][ny][nz] = u;
                q.push(v);
            }
        }
    }
    if (pos == UNDEFINED) {
        cout << "imposible\n";
        return 0;
    }
    vector<pair<int, int>> ans;
    for (auto &[x, y, z] = pos; pos != END; pos = par[x][y][z]) {
        ans.emplace_back(x, y);
    }
    cout << sz(ans) << '\n';
    for (auto [x, y] : ans) {
        cout << '(' << x << ',' << y << ")\n";
    }
    
    return 0;
}
