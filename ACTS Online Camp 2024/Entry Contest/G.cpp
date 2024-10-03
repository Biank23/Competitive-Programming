#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll,ll>;

const ll INF = 1e18;
const int MAXN = 1e5 + 9;

vector<ii> adj[MAXN];

vector<ll> dijkstra(int s, int n, auto cond) {
    vector<ll> dist(n, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(dist[s] = 0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (cond(w) && d + w < dist[v]) {
                pq.emplace(dist[v] = d + w, v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u,w);
    }
    int a,b;
    cin >> a >> b;
    vector<ll> ds = dijkstra(s,n,[&](ll w){ return w <= a; });
    vector<ll> dt = dijkstra(t,n,[&](ll w){ return w >= b; });
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, ds[i] + dt[i]);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}