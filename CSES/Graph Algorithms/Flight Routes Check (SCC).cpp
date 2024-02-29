#include <bits/stdc++.h>
 
using namespace std;
 
using vi = vector<int>;
 
const int MAX_N = 1e5;
 
bitset<MAX_N> vis;
int lastReached = -1;
 
void dfs(int u, vector<vi> &adj) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj);
    }
    lastReached = u;
} 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vi> adj(n), adjT(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i, adj);
    }
    
    vis.reset();
    dfs(lastReached, adjT);
    
    if (vis.count() == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        int v = vis._Find_first() + 1;
        int u = vis.flip()._Find_first() + 1;
        cout << u << ' ' << v << '\n';
    }
    
    return 0;
}
