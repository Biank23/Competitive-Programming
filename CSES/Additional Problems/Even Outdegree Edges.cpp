#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int MAX_N = 1e5+9;
 
bitset<MAX_N> vis, deg;
int t[MAX_N], timer = 0;
vector<int> adj[MAX_N];
vector<ii> res;
 
void addEdge(int from, int to) {
    res.emplace_back(from + 1, to + 1);
    deg[from] = !deg[from];
}
 
void dfs(int u, int p = -1) {
    vis[u] = true;
    t[u] = timer++;
    for (int v : adj[u]) if (v != p) {
        if (!vis[v]) dfs(v, u);
        if (t[u] < t[v]) {
            if (deg[v]) addEdge(v, u);
            else addEdge(u, v);
        }
    }
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
    }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }
    
    if (deg.none()) {
        for (auto [u, v] : res) {
            cout << u << ' ' << v << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}
