#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 5e4;
 
bitset<MAX_N> reachable[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u) {
    reachable[u][u] = true;
    for (int v : adj[u]) {
        if (!reachable[v][v]) dfs(v);
        reachable[u] |= reachable[v];
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
        adj[u - 1].push_back(v - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!reachable[i][i]) dfs(i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << reachable[i].count() << ' ';
    }
    
    return 0;
}