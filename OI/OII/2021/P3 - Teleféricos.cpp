#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int MAX_N = 5e5 + 9;

vector<pair<int, int>> adj[MAX_N];
int depth[MAX_N], par[MAX_N];

struct Val {
    int furthest, maxDiameter;
    Val(int v = 0) {
        furthest = v;
        maxDiameter = v;
    }
};

void merge(Val &a, Val b, int w) {
    a.maxDiameter = max({a.maxDiameter, a.furthest + b.furthest + w, b.maxDiameter});
    a.furthest = max(a.furthest, b.furthest + w);
}

Val dpDown[MAX_N], dpUp[MAX_N];

void dfsDown(int u, int p = 0, int d = 0) {
    depth[u] = d, par[u] = p;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dfsDown(v, u, d + 1);
        merge(dpDown[u], dpDown[v], w);
    }
}

void dfsUp(int u, int p = 0, int pw = 0, Val upVal = Val()) {
    dpUp[u] = upVal;
    int m = sz(adj[u]);
    vector<Val> pref(m + 1);
    pref[0] = Val();
    for (int i = 0; i < m; i++) {
        pref[i + 1] = pref[i];
        auto [v, w] = adj[u][i];
        if (v != p) merge(pref[i + 1], dpDown[v], w);
    }
    vector<Val> suff(m + 1);
    for (int i = m - 1; i >= 0; i--) {
        suff[i] = suff[i + 1];
        auto [v, w] = adj[u][i];
        if (v != par[u]) merge(suff[i], dpDown[v], w);
    }
    suff[m] = Val();
    for (int i = 0; i < m; i++) {
        auto [v, w] = adj[u][i];
        if (v == p) continue;
        Val nextUp = pref[i];
        merge(nextUp, suff[i + 1], 0);
        merge(nextUp, upVal, pw);
        dfsUp(v, u, w, nextUp);
    }
}

const int INF = 2e9;
const int MAX_K = 20;

int up[MAX_K][MAX_N], val[MAX_K][MAX_N];

void init(int n) {
    depth[0] = -1;
    dfsDown(1);
    dfsUp(1);
    dpUp[0] = dpDown[0] = INF;
    for (int u = 0; u <= n; u++) {
        up[0][u] = par[u];
        val[0][u] = abs(dpDown[u].maxDiameter - dpUp[par[u]].maxDiameter);
    }
    for (int i = 0; i < MAX_K - 1; i++) {
        for (int u = 0; u <= n; u++) {
            int v = up[i][u];
            up[i + 1][u] = up[i][v];
            val[i + 1][u] = min(val[i][u], val[i][v]);
        }
    }
}

int jump(int &u, int k) {
    int ans = INF;
    if (k == -1) return ans;
    for (int i = 0; i < MAX_K; i++) {
        if (k >> i & 1) {
            ans = min(ans, val[i][u]);
            u = up[i][u];
        }
    }
    return ans;
}

int query(int u, int v) {
    if (u == v) return INF;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    int ans = jump(u, diff - 1);
    if (par[u] == v) return ans;
    if (diff > 0) {
        ans = min(ans, val[0][u]);
        u = par[u];
    }
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            ans = min({ans, val[i][u], val[i][v]});
            u = up[i][u], v = up[i][v];
        }
    }
    return min(ans, abs(dpDown[u].maxDiameter - dpDown[v].maxDiameter));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    init(n);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int res = query(u, v);
        if (res == INF) cout << "-1\n"; 
        else cout << res << '\n';
    }
    
    return 0;
}