#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
const int MOD = 1e9 + 7;
 
bitset<MAX_N> vis;
vector<int> adj[MAX_N];
stack<int> order;
int ways[MAX_N];
 
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
    
    ways[0] = 1;
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        for (int v : adj[u]) {
            ways[v] += ways[u];
            if (ways[v] >= MOD) {
                ways[v] -= MOD;
            }
        }
    }
    
    cout << ways[n - 1] << '\n';
    
    return 0;
}
