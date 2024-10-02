#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
const int MAX_N = 1e5 + 9;
 
using vi = vector<int>;
 
int timer = 0;
stack<int> st;
bool vis[MAX_N];
int val[MAX_N], low[MAX_N];
vi g[MAX_N];
vector<vi> comps;
 
void dfs(int u, int p = -1) {
    vis[u] = true;
    val[u] = low[u] = ++timer;
    st.push(u);
    for (int v : g[u]) if (v != p) {
        if (vis[v]) {
            low[u] = min(low[u], val[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= val[u]) {
                vi cmp{u};
                while (cmp.empty() || cmp.back() != v) {
                    cmp.push_back(st.top());
                    st.pop();
                }
                comps.push_back(cmp);
            }
        }
    }
}
 
const int MAX_K = 18;
 
vi adj[2 * MAX_N];
int up[MAX_K][2 * MAX_N];
int depth[2 * MAX_N];
 
void dfs2(int u, int p = 0, int d = 0) {
    up[0][u] = p;
    depth[u] = d;
    for (int v : adj[u]) if (v != p) dfs2(v, u, d + 1);
}
 
void build(int n) {
    dfs(0);
    for (int i = 0; i < sz(comps); i++) {
        for (int u : comps[i]) {
            adj[u].push_back(n + i);
            adj[n + i].push_back(u);
        }
    }
    dfs2(0);
    for (int i = 0; i < MAX_K - 1; i++) {
        for (int j = 0; j < n + sz(comps); j++) {
            up[i + 1][j] = up[i][up[i][j]];
        }
    }
}
 
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < MAX_K; i++) {
        if (diff >> i & 1) u = up[i][u];
    }
    if (u == v) return u;
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u], v = up[i][v];
        }
    }
    return up[0][u];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build(n);
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b, --c;
        #define is_ancestor(x, y) (lca(x, y) == x)
        if (is_ancestor(lca(a, b), c) && (is_ancestor(c, a) || is_ancestor(c, b))) cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}