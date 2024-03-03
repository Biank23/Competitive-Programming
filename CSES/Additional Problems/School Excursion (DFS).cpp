#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5 + 9;
 
vector<int> adj[MAX_N];
bitset<MAX_N> vis, dp;
 
int dfs(int u) {
    vis[u] = true;
    int sz = 1;
    for (int v : adj[u]) {
        if (!vis[v]) sz += dfs(v);
    }
    return sz;
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
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dp |= dp << dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i];
    }
    
    return 0;
}