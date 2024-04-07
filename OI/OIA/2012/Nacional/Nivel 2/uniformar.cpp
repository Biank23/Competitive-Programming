#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const vector<ii> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    freopen("uniformar.in", "r", stdin);
	freopen("uniformar.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    
    queue<ii> q, nextQ;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    q.emplace(0, 0);
    vis[0][0] = true;
    int dist = 0;
    while (!q.empty()) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : d) {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < n &&
                    0 <= ny && ny < n &&
                    !vis[nx][ny]) {
                        if (g[x][y] == g[nx][ny]) {
                            q.emplace(nx, ny);
                        } else {
                            nextQ.emplace(nx, ny);
                        }
                        vis[nx][ny] = true;
                }
            }
        }
        dist++;
        swap(q, nextQ);
    }
    cout << dist - 1 << '\n';
    
    
    return 0;
}
