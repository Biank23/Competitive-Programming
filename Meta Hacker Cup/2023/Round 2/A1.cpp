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

void dfs(int x, int y) {
    grid[x][y] = '-';
    for (int i = 0; i < 4; i++) {
        int nX = x + dx[i], nY = y + dy[i];
        if (!valid(nX, nY)) continue;
        if (grid[nX][nY] == '.') b.emplace(nX, nY);
        else if (grid[nX][nY] == 'W') dfs(nX, nY);
    }
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
        
        bool found = false;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'W') {
                    b.clear();
                    dfs(i, j);
                    if (sz(b) == 1) found = true;
                }
            }
        }
        
        cout << "Case #" << tt << ": ";
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
