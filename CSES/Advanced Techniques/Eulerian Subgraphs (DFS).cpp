#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
 
vector<int> adj[MAX_N];
int vis[MAX_N], backEdges = 0;
 
void dfs(int u, int p = -1) {
    vis[u] = 1;
    for (int v : adj[u]) if (v != p) {
        if (vis[v] == 0) {
            dfs(v, u);
        } else if (vis[v] == 1) {
            backEdges++;
        }
    }
    vis[u] = 2;
}
 
const int MOD = 1e9 + 7;
 
int mul(int a, int b) {
    return 1LL * a * b % MOD;
}
 
int binpow(int a, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
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
        if (vis[i] == 0) dfs(i);
    }
    
    cout << binpow(2, backEdges) << '\n';
    
    return 0;
}
