#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e4;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 1e18;

vector<ii> adj[MAX_N];
int n, m;

vector<ll> dijkstra(int s) {
    vector<ll> dist(n, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(dist[s] = 0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                pq.emplace(dist[v] = d + w, v);
            }
        }
    }
    return dist;
}

ll memo[MAX_N];
int s, e;
vector<ll> distToS, distToE;

ll dp(int u) {
    if (u == e) return 1;
    ll &ans = memo[u];
    if (ans != -1) return ans;
    ans = 0;
    for (auto [v, w] : adj[u]) {
        if (distToS[u] < distToS[v] && distToE[u] > distToE[v]) {
            ans += dp((int) v);
        }
    }
    return ans;
}

int main() {
    freopen("ambulancia.in", "r", stdin);
	freopen("ambulancia.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> s >> e;
    --s, --e;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    distToS = dijkstra(s);
    distToE = dijkstra(e);
    memset(memo, -1, sizeof memo);
    cout << dp(s) << '\n';
    
    return 0;
}
