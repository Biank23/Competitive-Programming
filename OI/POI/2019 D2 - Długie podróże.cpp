#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5;
const int K = 300;
const int INF = 1e9;

int dist[K][MAX_N];
vector<int> adj[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(0));
    
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < K; i++) {
        for (int u = 0; u < n; u++) dist[i][u] = INF;
        queue<int> q;
        int s = rand() % n;
        dist[i][s] = 0, q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) if (dist[i][v] == INF) {
                dist[i][v] = dist[i][u] + 1, q.push(v);
            }
        }
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        int res = INF;
        for (int i = 0; i < K; i++) {
            res = min(res, dist[i][s] + dist[i][t]);
        }
        cout << res << '\n';
    }
    
    return 0;
}