#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int MAX_N = 1e5 + 9;
 
bitset<MAX_N> vis;
int first[MAX_N], low[MAX_N], timer = 0;
vector<ii> adj[MAX_N];
ii edge[2 * MAX_N];
 
bool hasBridges = false;
 
void dfs(int u, int p = -1) {
    vis[u] = true;
    low[u] = first[u] = timer;
    timer++;
    for (auto [v, i] : adj[u]) if (v != p) {
        auto &[from, to] = edge[i];
        if (!from) {
            from = u + 1;
            to = v + 1;
        }
        if (vis[v]) {
            low[u] = min(low[u], first[v]);
        } else {
            dfs(v, u);
            if (low[v] > first[u]) {
                hasBridges = true;
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
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    
    dfs(0);
    
    bool allVis = true;
    for (int i = 0; i < n; i++) {
        allVis &= vis[i];
    }
    
    if (allVis && !hasBridges) {
        for (int i = 0; i < m; i++) {
            auto [u, v] = edge[i];
            cout << u << ' ' << v << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}