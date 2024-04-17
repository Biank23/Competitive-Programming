#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())

using ll = long long;

struct Edge {
    int from, to;
    ll capacity, cost;
};

vector<Edge> graph;

const int MAX_N = 200;
const ll INF = 1e18;

int par[MAX_N], N;
ll dist[MAX_N];

bool bellmanFord(int s, int e) {
    for (int i = 0; i < N; i++) {
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

ll minCostFlow(int s, int e) {
    ll ans = 0;
    while (bellmanFord(s, e)) {
        ll flow = INF;
        for (int u = e; u != s; u = graph[par[u]].from) {
            flow = min(flow, graph[par[u]].capacity);
        }
        for (int u = e; u != s; u = graph[par[u]].from) {
            graph[par[u]].capacity -= flow;
            graph[par[u] ^ 1].capacity += flow;
        }
        ans += flow * dist[e];
    }
    return ans;
}

int idx[MAX_N][MAX_N];

void addEdge(int u, int v, int r, int c) {
    idx[u][v] = sz(graph);
    graph.emplace_back(u, v, r, c);
    graph.emplace_back(v, u, 0, -c);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    N = 2 * n + 2;
    
    int s = 0, e = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        addEdge(s, i, a, 0);
    }
    for (int j = n + 1; j <= 2 * n; j++) {
        int b;
        cin >> b;
        addEdge(j, e, b, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            int c;
            cin >> c;
            addEdge(i, j, 1, -c);
        }
    }
    ll ans = -minCostFlow(s, e);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (graph[idx[s][i]].capacity) flag = false;
    }
    for (int j = n + 1; j <= 2 * n; j++) {
        if (graph[idx[j][e]].capacity) flag = false;
    }
    if (!flag) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            if (graph[idx[i][j] ^ 1].capacity) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
    
    return 0;
}
