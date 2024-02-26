#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
using ll = long long;
using ii = pair<ll, ll>;
 
const ll INF = 1e18;
 
vector<ii> adj[MAX_N];
ll dist[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
    }
    
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(dist[0] = 0, 0);
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
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    
    return 0;
}