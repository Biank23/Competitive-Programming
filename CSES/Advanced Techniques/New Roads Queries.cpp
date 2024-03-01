#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
struct DSU {
    vector<int> par, sz;
    DSU(int n) : par(n), sz(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        return true;
    }
};
 
struct LCA {
    int n, k;
    vector<vector<int>> up, maxi;
    vector<int> depth;
    void dfs(vector<vector<ii>> &adj, int u, int p, int m = 0, int d = 0) {
        depth[u] = d;
        up[0][u] = p;
        maxi[0][u] = m;
        for (int i = 1; i < k; i++) {
            int v = up[i - 1][u];
            up[i][u] = up[i - 1][v];
            maxi[i][u] = max(maxi[i - 1][u], maxi[i - 1][v]);
        }
        for (auto [v, w] : adj[u]) {
            if (v != p) dfs(adj, v, u, w, d + 1);
        }
    }
    LCA(vector<vector<ii>> &adj) {
        n = ssize(adj);
        k = int(ceil(log2(n))) + 1;
        up.assign(k, vector<int>(n));
        maxi.assign(k, vector<int>(n));
        depth.assign(n, -1);
        for (int i = 0; i < n; i++) {
            if (depth[i] == -1) dfs(adj, i, i);
        }
    }
    int query(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int res = 0, dist = depth[a] - depth[b];
        for (int i = 0; i < k; i++) {
            if (dist >> i & 1) {
                res = max(res, maxi[i][a]);
                a = up[i][a];
            }
        }
        if (a == b) return res;
        for (int i = k - 1; i >= 0; i--) {
            if (up[i][a] != up[i][b]) {
                res = max({res, maxi[i][a], maxi[i][b]});
                a = up[i][a], b = up[i][b];
            }
        }
        res = max({res, maxi[0][a], maxi[0][b]});
        return res;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    DSU dsu(n);
    vector<vector<ii>> adj(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (dsu.unite(u, v)) {
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }
    
    LCA lca(adj);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (dsu.find(u) != dsu.find(v)) {
            cout << "-1\n";
        } else {
            cout << lca.query(u, v) << '\n';
        }
    }
    
    return 0;
}