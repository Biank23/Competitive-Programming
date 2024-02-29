#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 1e5;
 
bitset<MAX_N> vis;
vector<int> adj[MAX_N];
stack<int> order;
ll dist[MAX_N];
int par[MAX_N];
 
void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
    order.push(u);
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
    }
    
    dfs(0);
    
    if (!vis[n - 1]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    memset(par, -1, sizeof par);
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        for (int v : adj[u]) if (dist[v] < dist[u] + 1) {
            dist[v] = dist[u] + 1;
            par[v] = u;
        }
    }
    
    int u = n - 1;
    while (u != -1) {
        order.push(u);
        u = par[u];
    }
    
    cout << dist[n - 1] + 1 << '\n';
    while (!order.empty()) {
        cout << order.top() + 1 << ' ';
        order.pop();
    }
    
    return 0;
}
