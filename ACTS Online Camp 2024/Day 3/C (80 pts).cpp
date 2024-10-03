#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define pb push_back

using ii = pair<int, int>;
using vi = vector<int>;

const int MAX_N = 3e5 + 1;
const int MAX_H = 19;
const int LIMIT = 1e9;

int sz[MAX_N];
bitset<MAX_N> done;
vi adj[MAX_N];
vector<ii> adjW[MAX_N];
 
inline int getSize(int u, int p = -1) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !done[v]) {
            sz[u] += getSize(v, u);
        }
    }
    return sz[u];
}

inline int findCentroid(int u, int size, int p = -1) {
    for (int v : adj[u]) {
        if (v != p && !done[v] && sz[v] > size / 2) {
            return findCentroid(v, size, u);
        }
    }
    return u;
}

int dist[MAX_H][MAX_N];
int a[MAX_N], height[MAX_N];
vi c[MAX_N];

inline void dfs(int u, int h, int s, int p = -1, int d = 0) {
    if (d > LIMIT) return;
    dist[h][u] = d, c[s].pb(u);
    for (auto [v, w] : adjW[u]) {
        if (v != p && !done[v]) dfs(v, h, s, u, d + w);
    }
}

void buildCentroid(int u, int h = 0) {
    int size = getSize(u);
    u = findCentroid(u, size);
    done[u] = true, height[u] = h;
    dfs(u, h, u);
    for (int v : adj[u]) {
        if (!done[v]) buildCentroid(v, h + 1);
    }
}

const int MAX_NODES = MAX_N * MAX_H;

vi g[MAX_NODES], r[MAX_NODES];

inline void addEdge(int u, int v) {
    g[u].pb(v), r[v].pb(u);
}

bitset<MAX_NODES> vis;
int cmp[MAX_NODES];
stack<int> order;
 
inline void topsort(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) topsort(v);
    }
    order.push(u);
}
 
inline void paint(int u, int color) {
    cmp[u] = color;
    for (int v : r[u]) {
        if (!cmp[v]) paint(v, color);
    }
}

vi adjSCC[MAX_NODES];

inline void dfsSCC(int u) {
    for (int v : adjSCC[u]) {
        if (!vis[v]) {
            vis[v] = true;
            dfsSCC(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].pb(v), adjW[u].emplace_back(v, w);
        adj[v].pb(u), adjW[v].emplace_back(u, w);
    }
    buildCentroid(0);
    int nodes = n;
    for (int u = 0; u < n; u++) {
        int m = sz(c[u]);
        int h = height[u];
        sort(all(c[u]), [&](const int x, const int y) {
            return dist[h][x] < dist[h][y];
        });
        for (int i = 1; i < m; i++) {
            addEdge(nodes + i, nodes + i - 1);
        }
        for (int i = 0; i < m; i++) {
            addEdge(nodes + i, c[u][i]);
        }
        vi o = c[u];
        sort(all(o), [&](const int x, const int y) {
            return a[x] - dist[h][x] < a[y] - dist[h][y];
        });
        int j = -1;
        for (int i = 0; i < m; i++) {
            while (j + 1 < m && dist[h][c[u][j + 1]] <= a[o[i]] - dist[h][o[i]]) j++;
            if (j != -1) addEdge(o[i], nodes + j);
        }
        nodes += m;
    }
    for (int i = 0; i < nodes; i++) {
        if (!vis[i]) topsort(i);
    }
    int colors = 0;
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (!cmp[u]) paint(u, ++colors);
    }
    for (int i = 0; i < nodes; i++) {
        for (int j : g[i]) {
            if (cmp[i] != cmp[j]) adjSCC[cmp[i]].pb(cmp[j]);
        }
    }
    vis.reset();
    for (int i = 0; i < n; i++) {
        if (!vis[cmp[i]]) dfsSCC(cmp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[cmp[i]]) {
            ans++;
            vis[cmp[i]] = true;
        }
    }
    cout << ans << '\n';
    
    return 0;
}