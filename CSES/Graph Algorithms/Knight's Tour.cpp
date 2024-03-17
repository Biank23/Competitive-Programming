#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
const int N = 8;
 
const int dx[N] = {1, 1, -1, -1, 2, 2, -2, -2},
          dy[N] = {-2, 2, -2, 2, -1, 1, -1, 1};
          
int vis[N][N];
 
bool valid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N && !vis[x][y];
}
 
int count(int x, int y) {
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (valid(x + dx[i], y + dy[i])) c++;
    }
    return c;
}
 
bool dfs(int x, int y, int step) {
    vis[x][y] = step;
    if (step == N * N) {
        return true;
    }
    vector<tuple<int, int, int>> pos;
    for (int i = 0; i < N; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny)) {
            pos.emplace_back(count(nx, ny), nx, ny);
        }
    }
    sort(all(pos));
    for (auto &[_, nx, ny] : pos) {
        if(dfs(nx, ny, step+1)) return true;
    }
    vis[x][y] = 0;
    return false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int x, y;
    cin >> x >> y;
    dfs(y - 1, x - 1, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}