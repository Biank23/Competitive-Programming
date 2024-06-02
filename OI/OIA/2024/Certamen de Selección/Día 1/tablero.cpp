#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int,int>;

const int N = 8;

ii pos(string s){
    int fil = s[0] - 'a';
    int col = N - (s[1] - '0');
    return {col, fil};
}

int dist[N][N][N];
bool done[N][N][N];
const int INF = 1e9;

using State = tuple<int, int, int>;

int tablero(string &pieza, string &salida, string &llegada, vector<string> &escaques) {
    ii s = pos(salida), e = pos(llegada);
    vector<int> dx, dy;
    bool r = false;
    if (pieza == "caballo") {
        dx = {2, 2, -2, -2, 1, 1, -1, -1};
        dy = {1, -1, 1, -1, 2, -2, 2, -2};
    } else if (pieza == "torre") {
        dx = {1, 0, -1, 0};
        dy = {0, 1, 0, -1};
        r = true;
    } else if (pieza == "rey") {
        dx = {1, 0, -1, 0, 1, 1, -1, -1};
        dy = {0, 1, 0, -1, 1, -1, 1, -1};
    } else if (pieza == "dama") {
        dx = {1, 0, -1, 0, 1, 1, -1, -1};
        dy = {0, 1, 0, -1, 1, -1, 1, -1};
        r = true;
    } else if (pieza == "alfil") {
        dx = {1, -1, 1, -1};
        dy = {1, 1, -1,-1};
        r = true;
    } else assert(false);
    int m = sz(dx);
    deque<State> dq;
    dq.emplace_back(s.first, s.second, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dist[i][j][k] = INF;
            }
        }
    }
    dist[s.first][s.second][0] = 0;
    bool flag = false;
    while (!dq.empty()) {
        auto [x, y, move] = dq.front();
        dq.pop_front();
        if (done[x][y][move]) continue;
        done[x][y][move] = true;
        for (int i = 0; i < m; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
            if (escaques[nx][ny] == 'X') continue;
            int cost = i != move || !flag;
            if (dist[nx][ny][i] > dist[x][y][move] + cost) {
                dist[nx][ny][i] = dist[x][y][move] + cost;
                if (cost==1) dq.emplace_back(nx, ny, i);
                else dq.emplace_front(nx, ny, i);
            }
        }
        if (r) flag = true;
    }
    int ans = INF;
    for (int i = 0; i < m; i++) {
        ans = min(ans, dist[e.first][e.second][i]);
    }
    if (ans == INF) return -1;
    return ans;
}
