#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
const int MAX_K = 18;
 
vector<int> adj[MAX_N];
int up[MAX_K][MAX_N], d[MAX_N];
 
void dfs(int u, int h = 0) {
    d[u] = h;
    for (int v : adj[u]) {
        dfs(v, h + 1);
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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        up[0][i] = p;
    }
    
    init(n), dfs(1);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}