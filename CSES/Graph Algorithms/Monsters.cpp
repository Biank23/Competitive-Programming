#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
using vi = vector<int>;
 
vector<string> labyrinth;
 
const int MOVES = 4;
const int dx[MOVES] = {1, -1, 0, 0};
const int dy[MOVES] = {0, 0, 1, -1};
const string dir = "DURL";
 
const ii UNDEFINED = {-1, -1};
 
const int INF = 1e9;
 
int n, m;
 
bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
pair<ii, vector<vi>> bfs(vector<ii> &source, vector<vi> distToMonsters, bool second = false) {
    vector<vi> dist(n, vi(m, INF)), par(n, vi(m, -1));
    queue<ii> q;
 
    for (auto [x, y] : source) {
        dist[x][y] = 0;
        q.emplace(x, y);
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i], nextY = y + dy[i];
            if (!valid(nextX, nextY)) {
                if (second) {
                    ii e = {x, y};
                    return {e, par};
                }
                continue;
            }
            if (labyrinth[nextX][nextY] != '.') {
                continue;
            }
            if (distToMonsters[nextX][nextY] <= dist[x][y] + 1) {
                continue;
            }
            if (dist[nextX][nextY] > dist[x][y] + 1) {
                dist[nextX][nextY] = dist[x][y] + 1;
                par[nextX][nextY] = i;
                q.emplace(nextX, nextY);
            }
        }
    }
    
    return {UNDEFINED, dist};
}
 
#define all(x) begin(x), end(x)
 
int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    vector<ii> monsters, start;
    
    labyrinth.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                start.emplace_back(i, j);
            }
            if (labyrinth[i][j] == 'M') {
                monsters.emplace_back(i, j);
            }
        }
    }
    auto [_, distToMonsters] = bfs(monsters, vector<vi>(n, vi(m, INF)), false);
    auto [e, par] = bfs(start, distToMonsters, true);
    
    if (e == UNDEFINED)  {
        cout << "NO\n";
        return 0;
    }
 
    cout << "YES\n";
    
    string path = "";
    ii s = start.front();
    auto &[x, y] = e;
    while (e != s) {
        int p = par[x][y];
        path += dir[p];
        x -= dx[p];
        y -= dy[p];
    }
 
    reverse(all(path));
    cout << ssize(path) << '\n';
 
    cout << path << '\n';
 
    return 0;
}
