#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
using ll = long long;
using ii = pair<ll, ll>;
using Edge = tuple<int, int, int>;
 
const ll INF = 1e18;
 
vector<ll> dijkstra(int s, vector<vector<ii>> &adj) {
    int n = ssize(adj);
    vector<ll> dist(n, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(dist[s] = 0, s);
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (dist[u] < du) continue;
        for (auto [v, w] : adj[u]) {
            if (du + w < dist[v]) {
                pq.emplace(dist[v] = du + w, v);
            }
        }
    }
    return dist;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<ii>> adj(n), adjT(n);
    vector<Edge> graph(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adjT[v].emplace_back(u, w);
        graph[i] = {u, v, w};
    }
    vector<ll> distFromSyrjala = dijkstra(0, adj);
    vector<ll> distFromMetsala = dijkstra(n - 1, adjT);
    
    ll res = INF;
    for (auto [u, v, w] : graph) {
        res = min(res, distFromSyrjala[u] + w / 2 + distFromMetsala[v]);
    }
    cout << res << '\n';
    
    return 0;
}
