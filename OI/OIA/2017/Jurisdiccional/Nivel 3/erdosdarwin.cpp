#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5;
const int INF = 1e9;

using vi = vector<int>;

int n;
vi adj[MAX_N];

vi bfs(int s) {
    vi dist(n, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi erdos = bfs(0), darwin = bfs(n - 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (erdos[i] + darwin[i] <= d) ans++;
    }
    cout << ans << '\n';
    
    return 0;
}
