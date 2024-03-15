#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int dfs(int u, int p, vector<bool> &vis, const vector<vector<int>> &adj) {
    vis[u] = true;
    for (auto v : adj[u]) if (v != p) {
        if (!vis[v]) {
            int c = dfs(v, u, vis, adj);
            if (c != -1) return c;
        } else {
            return v;
        }
    }
    return -1;
}

vector<int> bfs(int start, const vector<vector<int>> &adj) {
    int n = sz(adj);
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n, a, b;
        cin >> n >> a >> b;
        --a, --b;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n, false);
        int c = dfs(b, -1, vis, adj);
        vector<int> dist = bfs(c, adj);
        
        if (dist[b] < dist[a]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
