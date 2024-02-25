#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N];
int with[MAX_N], without[MAX_N];
 
int dfs(int u, int p = -1) {
    for (int v : adj[u]) if (v != p) {
        without[u] += dfs(v, u);
    }
    for (int v : adj[u]) if (v != p) {
        with[u] = max(with[u], without[u] - with[v] + without[v] + 1);
    }
    return max(with[u], without[u]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(0) << '\n';
    
    return 0;
}