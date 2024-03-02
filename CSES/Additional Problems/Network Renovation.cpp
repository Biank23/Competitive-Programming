#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5 + 5;
 
vector<int> adj[MAX_N], leaf;
 
void dfs(int u, int p = 0) {
    if (ssize(adj[u]) == 1) {
        leaf.push_back(u);
    }
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1);
    
    int c = ssize(leaf);
    int k = (c + 1) / 2;
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << leaf[i] << ' ' << leaf[i + c / 2] << '\n';
    }
    
    return 0;
}