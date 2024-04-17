#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500;

using ll = long long;

const ll INF = 1e18;

ll capacity[MAX_N][MAX_N];
vector<int> adj[MAX_N];
int par[MAX_N];

bool bfs(int s, int e) {
    queue<int> q;
    memset(par, -1, sizeof par);
    q.push(s), par[s] = -2;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && par[v] == -1) {
                q.push(v), par[v] = u;
            }
        }
    }
    return par[e] != -1;
}

ll maxFlow(int s, int e) {
    ll ans = 0;
    while (bfs(s, e)) {
        ll flow = INF;
        for (int u = e; u != s; u = par[u]) {
            flow = min(flow, capacity[par[u]][u]);
        }
        for (int u = e; u != s; u = par[u]) {
            capacity[par[u]][u] -= flow;
            capacity[u][par[u]] += flow;
        }
        ans += flow;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += w;
    }
    cout << maxFlow(0, n - 1) << '\n';
    
    return 0;
}
