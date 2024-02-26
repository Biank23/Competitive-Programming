#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5 + 9;
 
vector<int> adj[MAX_N];
bitset<MAX_N> vis;
vector<int> order, cycle;
 
bool dfs(int u, int p = 0) {
    vis[u] = true;
    order.push_back(u);
    for (int v : adj[u]) if (v != p) {
        if (vis[v]) {
            cycle.push_back(v);
            while (order.back() != v) {
                cycle.push_back(order.back());
                order.pop_back();
            }
            cycle.push_back(v);
            return true;
        } else if (dfs(v, u)) {
            return true;
        }
    }
    order.pop_back();
    return false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i)) {
            cout << ssize(cycle) << '\n';
            for (int u : cycle) {
                cout << u << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}