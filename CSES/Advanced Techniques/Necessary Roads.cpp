#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int MAX_N = 1e5;
 
bitset<MAX_N> vis;
int first[MAX_N], low[MAX_N], timer = 0;
vector<int> adj[MAX_N];
vector<ii> bridges;
 
void dfs(int u, int p = -1) {
    vis[u] = true;
    low[u] = first[u] = timer;
    timer++;
    for (int v : adj[u]) if (v != p) {
        if (vis[v]) {
            low[u] = min(low[u], first[v]);
        } else {
            dfs(v, u);
            if (low[v] > first[u]) {
                bridges.emplace_back(u, v);
            } else {
                low[u] = min(low[u], low[v]);
            }
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
    
    dfs(0);
    
    cout << ssize(bridges) << '\n';
    for (auto [u, v] : bridges) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    
    return 0;
}