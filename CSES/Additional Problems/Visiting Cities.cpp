#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vll = vector<ll>;
using ii = pair<ll, ll>;
using vii = vector<ii>;
 
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distrib(ll(1e9), ll(2e9));
 
const ll INF = 1e14+10;
 
pair<vll, vll> dijkstra(int s, const vector<vii> &adj, ll MOD) {
    int n = ssize(adj);
    priority_queue<ii, vii, greater<ii>> pq;
    vll dist(n, INF), cant(n, 0);
    pq.emplace(dist[s] = 0, s);
    cant[s] = 1;
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for(auto [v,w]:adj[u]) {
            if (dist[v] > d + w) {
                pq.emplace(dist[v] = d + w, v);
                cant[v] = cant[u];
            } else if (dist[v] == d + w) {
                cant[v] += cant[u];
                if (cant[v] >= MOD) cant[v] -= MOD;
            }
        }
    }
    return {dist, cant};
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vii> adj(n), adjT(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adjT[v].emplace_back(u, w);
    }
    
    ll MOD = distrib(mt);
    
    auto [distToS, cantFromS] = dijkstra(0, adj, MOD);
    auto [distToL, cantFromL] = dijkstra(n-1, adjT, MOD);
    
    vll res;
    for (int i = 0; i < n; i++) {
        if (distToS[i] + distToL[i] == distToS[n-1] && cantFromS[i] * cantFromL[i] % MOD == cantFromS[n-1]) {
            res.push_back(i+1);
        }
    }
    
    cout << ssize(res) << '\n';
    for (ll u : res) {
        cout << u << ' ';
    }
    cout << '\n';
    
    return 0;
}