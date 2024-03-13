#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ii = pair<int, int>;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int MAX_N = 3003;

int r, c;
char grid[MAX_N][MAX_N];

bool valid(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

set<ii> b;

int dfs(int x, int y) {
    grid[x][y] = '-';
    int sz = 1;
    for (int i = 0; i < 4; i++) {
        int nX = x + dx[i], nY = y + dy[i];
        if (!valid(nX, nY)) continue;
        if (grid[nX][nY] == '.') b.emplace(nX, nY);
        else if (grid[nX][nY] == 'W') sz += dfs(nX, nY);
    }
    return sz;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        cin >> r >> c;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }
        
        vector<vector<int>> v(r, vector<int>(c, 0));
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'W') {
                    b.clear();
                    int sz = dfs(i, j);
                    if (sz(b) == 1) {
                        auto [x, y] = *b.begin();
                        v[x][y] += sz;
                        ans = max(ans, v[x][y]);
                    }
                }
            }
        }
        
        cout << "Case #" << tt << ": " << ans << '\n';
    }
    
    return 0;
}
