#include <bits/stdc++.h>
 
using namespace std;

using vi = vector<int>;
 
const int MAX_N = 1e5;
 
bitset<MAX_N> vis;
 
void dfs(int u, vector<vi> &adj) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj);
    }
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
    
    dfs(0, adj);
    if (vis.count() != n) {
        cout << "NO\n";
        cout << "1 " << vis.flip()._Find_first() + 1 << '\n';
        return 0;
    }
    
    vis.reset();
    dfs(0, adjT);
    if (vis.count() != n) {
        cout << "NO\n";
        cout << vis.flip()._Find_first() + 1 << " 1\n";
        return 0;
    }
    
    cout << "YES\n";
    
    return 0;
}