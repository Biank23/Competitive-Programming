#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

struct Edge {
    int from, to;
    ll capacity, cost;
};

vector<Edge> graph;

const int MAX_N = 500;
const ll INF = 1e18;

int par[MAX_N], n;
ll dist[MAX_N];

bool bellmanFord(int s, int e) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    bool any = true;
    while (any) {
        any = false;
        for (int i = 0; i < sz(graph); i++) {
            auto edge = graph[i];
            if (dist[edge.from] != INF && edge.capacity > 0 && dist[edge.from] + edge.cost < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.cost;
                par[edge.to] = i, any = true;
            }
        }
    }
    return dist[e] != INF;
}

vector<vector<int>> ans;

ll minCostFlow(int s, int e, int k, bool flag) {
    ll cost = 0;
    while (k > 0 && bellmanFord(s, e)) {
        ll flow = k;
        for (int u = e; u != s; u = graph[par[u]].from) {
            flow = min(flow, graph[par[u]].capacity);
        }
        vector<int> path;
        for (int u = e; u != s; u = graph[par[u]].from) {
            path.push_back(u);
            graph[par[u]].capacity -= flow;
            if (flag) graph[par[u] ^ 1].capacity += flow;
        }
        k -= (int) flow;
        cost += flow * dist[e];
        if (!flag) {
            path.push_back(s);
            while (flow--) ans.push_back(path);
        }
    }
    if (k > 0) return -1;
    return cost;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph.emplace_back(u, v, 1, 1);
        graph.emplace_back(v, u, 0, -1);
    }
    ll cost = minCostFlow(0, n - 1, k, true);
    cout << cost << '\n';
    if (cost == -1) return 0;
    for (int i = 0; i < 2 * m; i += 2) {
        graph[i].capacity -= 1;
    }
    minCostFlow(n - 1, 0, k, false);
    for (auto &path : ans) {
        cout << sz(path) << '\n';
        for (int u : path) {
            cout << u + 1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
