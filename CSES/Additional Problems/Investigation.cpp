#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ii = pair<ll, ll>;
 
const int MAX_N = 1e5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
vector<ii> adj[MAX_N];
ll dist[MAX_N];
int mini[MAX_N], maxi[MAX_N], cant[MAX_N];
 
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
    mini[0] = 0, maxi[0] = 0, cant[0] = 1;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                pq.emplace(dist[v] = d + w, v);
                mini[v] = mini[u] + 1;
                maxi[v] = maxi[u] + 1;
                cant[v] = cant[u];
            } else if (dist[v] == d + w) {
                mini[v] = min(mini[v], mini[u] + 1);
                maxi[v] = max(maxi[v], maxi[u] + 1);
                cant[v] += cant[u];
                if (cant[v] >= MOD) {
                    cant[v] -= MOD;
                }
            }
        }
    }
    cout << dist[n - 1] << ' ' << cant[n - 1] << ' ' << mini[n - 1] << ' ' << maxi[n - 1] << '\n';
    
    return 0;
}
SHARE CODE TO OTHERS