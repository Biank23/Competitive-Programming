#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto valid = [&](int x, int y){
            return 0 <= x && x < 2 && 0 <=y && y<n;
        };
        vector<string> grid(2);
        for (int i = 0; i < 2; i++) {
            cin >> grid[i];
        }
        vector<vector<bool>> vis(2, vector<bool>(n, false));
        queue<ii> q;
        q.emplace(0, 0);
        vis[0][0] = true;
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!valid(nx, ny)) continue;
                if (grid[nx][ny] == '<') ny--;
                else ny++;
                if (valid(nx, ny) && !vis[nx][ny]) {
                    q.emplace(nx, ny);
                    vis[nx][ny] = true;
                }
            }
        }
        if (vis[1][n - 1]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}
