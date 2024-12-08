#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

struct Edge {
    int from, to, weight;
    int forbidden = 0, cnt = 0;
};

const ll INF = 1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<Edge> graph(2 * m);
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            Edge e; int c;
            cin >> e.from >> e.to >> e.weight >> c;
            --e.from, --e.to, --c;
            if (c == -1) e.cnt++;
            else adj[c].push_back(2 * i), adj[c].push_back(2 * i + 1);
            graph[2 * i] = e;
            swap(e.from, e.to);
            graph[2 * i + 1] = e;
            adj[e.to].push_back(2 * i), adj[e.from].push_back(2 * i + 1);
        }
        vector<ll> dist(n, INF);
        vector<int> vis(n, 0);
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
        for (int i = 2; i >= 1; i--) {
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int s; cin >> s; --s;
                pq.emplace(dist[s] = 0, i, s);
            }
        }
        int ans = 0;
        while (!pq.empty()) {
            auto [_, p, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = p;
            if (p == 1) ans++;
            else ans--;
            for (int idx : adj[u]) {
                Edge &e = graph[idx];
                if (e.forbidden == p) continue;
                e.forbidden = 3 - p, e.cnt++;
                if (e.cnt == 2 && !vis[e.to] && dist[u] + e.weight <= dist[e.to]) {
                    pq.emplace(dist[e.to] = dist[u] + e.weight, p, e.to);
                }
            }
        }
        if (ans > 0) {
            cout << "La hora de juego\n" << ans << '\n';
        } else {
            cout << "Hasta luego Huize, es la hora de Olivia\n";
        }
    }
    
    return 0;
}