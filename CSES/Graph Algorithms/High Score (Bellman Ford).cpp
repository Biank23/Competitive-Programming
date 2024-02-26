#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const ll INF = 1e18;
 
struct Edge {
    int from, to;
    ll weight;
};
 
void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, vis, adj);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjN(n), adjR(n);
    vector<Edge> graph(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        adjN[u].push_back(v);
        adjR[v].push_back(u);
        graph[i] = {u, v, w};
    }
    vector<bool> visN(n, false), visR(n, false);
    dfs(0, visN, adjN);
    dfs(n - 1, visR, adjR);
    
    vector<ll> dist(n, -INF);
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [from, to, weight] : graph) {
            if (dist[to] < dist[from] + weight) {
                dist[to] = dist[from] + weight;
                if (i == n - 1 && visN[to] && visR[to]) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << dist[n - 1] << '\n';
    
    return 0;
}