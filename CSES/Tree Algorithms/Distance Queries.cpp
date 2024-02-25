#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
const int MAX_K = 18;
 
vector<int> adj[MAX_N];
int up[MAX_K][MAX_N], d[MAX_N];
 
void dfs(int u, int p = 0, int h = 0) {
    up[0][u] = p, d[u] = h;
    for (int v : adj[u]) {
        if (v != p) dfs(v, u, h + 1);
    }
}
 
void init(int n) {
    for (int i = 0; i < MAX_K - 1; i++) {
        for (int j = 1; j <= n; j++) {
            up[i + 1][j] = up[i][up[i][j]];
        }
    }
}
 
int lca(int a, int b) {
    if (d[a] < d[b]) {
        swap(a, b);
    }
    int diff = d[a] - d[b];
    for (int i = 0; i < MAX_K; i++) {
        if (diff>>i&1) a = up[i][a];
    }
    if (a == b) {
        return a;
    }
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}
 
int dist(int a, int b) {
    return d[a] + d[b] - 2 * d[lca(a, b)];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    init(n);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dist(a, b) << '\n';
    }
    
    return 0;
}