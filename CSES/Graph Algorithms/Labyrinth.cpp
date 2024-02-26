#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1000;
 
string grid[MAX_N];
 
const int MOVES = 4;
const int dx[MOVES] = {0, 1, 0, -1};
const int dy[MOVES] = {1, 0, -1, 0};
const string dir = "LURD";
 
using ii = pair<int, int>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    ii start, end;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') { //going backwards
                start = {i, j};
                grid[i][j] = '*';
            }
            if (grid[i][j] == 'A') {
                end = {i, j};
                grid[i][j] = '.';
            }
        }
    }
    
    queue<ii> q;
    q.push(start);
    
    auto valid = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < MOVES; i++) {
            if (valid(x + dx[i], y + dy[i]) && grid[x + dx[i]][y + dy[i]] == '.') {
                grid[x + dx[i]][y + dy[i]] = (char) i;
                q.emplace(x + dx[i], y + dy[i]);
            }
        }
    }
    
    auto [x, y] = end;
    if (grid[x][y] == '.') {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    
    string path = "";
    while (ii{x, y} != start) {
        int i = grid[x][y];
        x -= dx[i], y -= dy[i], path += dir[i];
    }
    cout << size(path) << '\n';
    cout << path << '\n';
    
    
    return 0;
}