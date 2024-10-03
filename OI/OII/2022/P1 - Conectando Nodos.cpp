#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ii = pair<int, int>;

const int MAX_N = 1e5 + 9;

int par[MAX_N], sz[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i, sz[i] = 1;
    }
}

int find(int x) {
    return par[x] = par[x] != x ? find(par[x]) : x;
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (sz[x] > sz[y]) swap(x, y);
        par[x] = y, sz[y] += sz[x];
    }
}

const int MAX_M = 2 * MAX_N;

map<int, vector<ii>> adj[MAX_N];
int c[MAX_N], vis[MAX_N];
bitset<MAX_M> done;

int dfs(int u, int x) {
    vis[u] = x;
    int cant = sz[u];
    for (auto &[v, idx] : adj[u][c[u] ^ x]) {
        done[idx] = true;
        if (vis[v] != x) cant += dfs(v, x);
    }
    return cant;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    init(n);
    vector<ii> graph(m);
    for (auto &[u, v] : graph) {
        cin >> u >> v; --u, --v;
        if (c[u] == c[v]) unite(u, v);
    }
    vector<ii> edges;
    int idx = 0;
    for (auto &[u, v] : graph) {
        u = find(u), v = find(v);
        if (u == v) continue;
        edges.emplace_back(u, v);
        adj[u][c[v]].emplace_back(v, idx);
        adj[v][c[u]].emplace_back(u, idx);
        idx++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, sz[i]);
    }
    for (int i = 0; i < idx; i++) {
        if (done[i]) continue;
        auto [u, v] = edges[i];
        ans = max(ans, dfs(u, c[u] ^ c[v]));
        
    }
    cout << ans << '\n';
    
    return 0;
}