#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5 + 9;
 
vector<int> adj[MAX_N];
bitset<MAX_N> vis;
 
void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            v.push_back(i);
        }
    }
    
    cout << ssize(v) - 1 << '\n';
    for (int i = 1; i < ssize(v); i++) {
        cout << v[i - 1] << ' ' << v[i] << '\n';
    }
    
    return 0;
}