#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
 
const int MAX_N = 500;
const int INF = 1e9;
 
using ii = pair<int, int>;
 
int capacity[MAX_N][MAX_N];
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
 
vector<ii> minCut(int s, int e, int n) {
    while (bfs(s, e)) {
        int flow = INF;
        for (int u = e; u != s; u = par[u]) {
            flow = min(flow, capacity[par[u]][u]);
        }
        for (int u = e; u != s; u = par[u]) {
            capacity[par[u]][u] -= flow;
            capacity[u][par[u]] += flow;
        }
    }
    bfs(s, e);
    vector<ii> ans;
    for (int u = 0; u < n; u++) {
        if (par[u] == -1) continue;
        for (int v : adj[u]) {
            if (par[v] == -1) ans.emplace_back(u, v);
        }
    }
    return ans;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v]++;
        capacity[v][u]++;
    }
    
    vector<ii> ans = minCut(0, n - 1, n);
    cout << sz(ans) << '\n';
    for (auto [u, v] : ans) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    
    return 0;
}
