#include <bits/stdc++.h>
 
using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
using ii = pair<int, int>;
using ll = long long;
 
const int MAX_N = 5e5 + 9;
const int MAX_K = 19;

vector<ii> adj[MAX_N];
int up[MAX_K][MAX_N];
int height[MAX_N];
ll dist[MAX_N];

void dfs(int u, int p = 0, int h = 0, ll d = 0) {
    up[0][u] = p;
    for (int i = 1; i < MAX_K; i++) {
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    height[u] = h, dist[u] = d;
    for (auto [v, w] : adj[u]) if (v != p) {
        dfs(v, u, h + 1, d + w);
    }
}

int lca(int u, int v) {
    if (height[u] < height[v]) swap(u, v);
    int diff = height[u] - height[v];
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

const ll INF = 1e9;

ll treeDistance(int u, int v) {
    int a = lca(u, v);
    if (a == 0) return INF;
    return dist[u] + dist[v] - 2 * dist[a];
}

const int MAX_J = 600;

ll dp[MAX_J][MAX_J];

struct Edge {
    int u, v, w;
};

void calculateDistances(vector<int> &nodes, vector<Edge> &edges) {
    const int S = sz(nodes);
    for (int i = 0; i < S; i++) {
        int u = nodes[i];
        for (int j = i; j < S; j++) {
            int v = nodes[j];
            dp[j][i] = dp[i][j] = treeDistance(u, v);
        }
    }
    #define pos(u) int(lower_bound(all(nodes), u) - begin(nodes))
    for (auto &[u, v, w] : edges) {
        int i = pos(u), j = pos(v);
        if (w < dp[i][j]) dp[j][i] = dp[i][j] = w;
    }
    for (int k = 0; k < S; k++) {
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, t, d;
    cin >> n >> m >> t >> d;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    memset(height, -1, sizeof height);
    for (int i = 0; i < n; i++) {
        if (height[i] == -1) dfs(i);
    }
    vector<Edge> edges(t);
    set<int> s;
    for (auto &[u, v, w] : edges) {
        cin >> u >> v >> w;
        s.insert(u), s.insert(v);
    }
    vector<int> nodes(all(s));
    calculateDistances(nodes, edges);
    const int S = sz(nodes);
    while (d--) {
        int a, b;
        cin >> a >> b;
        ll ans = treeDistance(a, b);
        vector<ll> distFromA(S), distToB(S);
        for (int i = 0; i < S; i++) {
            distFromA[i] = treeDistance(a, nodes[i]);
            distToB[i] = treeDistance(nodes[i], b);
        }
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                ans = min(ans, distFromA[i] + dp[i][j] + distToB[j]);
            }
        }
        if (ans == INF) cout << "-1\n";
        else cout << ans << '\n';
    }
    
    return 0;
}