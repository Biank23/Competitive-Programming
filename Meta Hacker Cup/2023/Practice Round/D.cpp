#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using ll = long long;

const int MAX_N = 3e5 + 20;

bitset<MAX_N> vis, isBridge;
int first[MAX_N], low[MAX_N], timer;
vector<ii> adj[MAX_N], bridges;
 
void getBridges(int u, int p = -1) {
    vis[u] = true;
    low[u] = first[u] = timer;
    timer++;
    for (auto [v, i] : adj[u]) if (v != p) {
        if (vis[v]) {
            low[u] = min(low[u], first[v]);
        } else {
            getBridges(v, u);
            if (low[v] > first[u]) {
                isBridge[i] = true;
                bridges.emplace_back(u, v);
            } else {
                low[u] = min(low[u], low[v]);
            }
        }
    }
}

int cmp[MAX_N], c[MAX_N];

bool dfs(int u, int component, int color = 0) {
    cmp[u] = component;
    c[u] = color;
    bool flag = false;
    for (auto [v, i] : adj[u]) if (!isBridge[i]) {
        if (cmp[v] == 0) {
            flag |= dfs(v, component, 1 - color);
        } else if (c[v] == color) {
            flag = true;
        } 
    }
    return flag;
}

int val[MAX_N];
vector<int> g[MAX_N];
int component;

void initBridgeTree(int n) {
    component = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!cmp[i]) {
            if (dfs(i, component)) {
                q.push(component);
                val[component] = 0;
                vis[component] = true;
            }
            component++;
        }
    }
    for (auto [u, v] : bridges) {
        g[cmp[u]].push_back(cmp[v]);
        g[cmp[v]].push_back(cmp[u]);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                q.push(v);
                val[v] = val[u] + 1;
                vis[v] = true;
            }
        }
    }
}

const int MAX_K = 19;

int up[MAX_K][MAX_N], mini[MAX_K][MAX_N];
int depth[MAX_N];

void dfsLCA(int u, int p, int d = 0) {
    up[0][u] = p;
    mini[0][u] = min(val[u], val[p]);
    depth[u] = d;
    for (int v : g[u]) {
        if (v != p) dfsLCA(v, u, d + 1);
    }
}

void initLCA() {
    for (int i = 1; i < component; i++) {
        if (depth[i] == -1) dfsLCA(i, i);
    }
    for (int i = 1; i < MAX_K; i++) {
        for (int u = 1; u < component; u++) {
            int v = up[i - 1][u];
            up[i][u] = up[i - 1][v];
            mini[i][u] = min(mini[i - 1][u], mini[i - 1][v]);
        }
    }
}

const int INF = 1e9;

int query(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int res = min(val[a], val[b]), dist = depth[a] - depth[b];
    for (int i = 0; i < MAX_K; i++) {
        if (dist >> i & 1) {
            res = min(res, mini[i][a]);
            a = up[i][a];
        }
    }
    if (a == b) return res;
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            res = min({res, mini[i][a], mini[i][b]});
            a = up[i][a], b = up[i][b];
        }
    }
    res = min({res, mini[0][a], mini[0][b]});
    a = up[0][a], b = up[0][b];
    if (a == b) return res;
    return INF;
}

void clear(int n, int m) {
    bridges.clear();
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        g[i].clear();
        vis[i] = false;
        cmp[i] = 0;
        c[i] = -1;
        depth[i] = -1;
        val[i] = INF;
    }
    timer = 0;
    for (int i = 0; i < m; i++) {
        isBridge[i] = false;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int TT;
	cin >> TT;
	for (int tt = 1 ; tt <= TT; tt++) {
		int n, m;
        cin >> n >> m;
        clear(n, m);
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
        
        getBridges(0);
        initBridgeTree(n);
        initLCA();
        
        int q;
        cin >> q;
        ll ans = 0;
        for (int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            ll r = query(cmp[u], cmp[v]);
            if (r == INF) r = -1;
            ans += r;
        }
        cout << "Case #" << tt << ": " << ans << '\n';
	}
}
