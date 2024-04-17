#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
 
const int MAX_N = 500;
 
using ii = pair<int, int>;
 
const int INF = 1e9;
 
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
 
vector<vector<int>> ans;
 
void maxFlow(int s, int e, bool flag = true) {
    while (bfs(s, e)) {
        int flow = INF;
        for (int u = e; u != s; u = par[u]) {
            flow = min(flow, capacity[par[u]][u]);
        }
        vector<int> path{e};
        for (int u = e; u != s; u = par[u]) {
            capacity[par[u]][u] -= flow;
            if (flag) capacity[u][par[u]] += flow;
            path.push_back(par[u]);
        }
        if (!flag) while (flow--) ans.push_back(path);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<ii> edges(m);
    for (auto &[u, v] : edges) {
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v]++;
    }
    maxFlow(0, n - 1);
    for (auto [u, v] : edges) {
        capacity[u][v]--;
    }
    maxFlow(n - 1, 0, false);
    cout << sz(ans) << '\n';
    for (auto &path : ans) {
        cout << sz(path) << '\n';
        for (int u : path) {
            cout << u + 1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
