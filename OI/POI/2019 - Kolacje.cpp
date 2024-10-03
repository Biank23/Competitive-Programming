#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x),end(x)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define forn(i,n) for(int i=0;i<int(n);i++)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
 
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
 
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;

struct LCA {
    vector<vector<pair<int, ll>>> adj;
    vector<vi> up;
    vector<vll> mini;
    vll val, dist;
    vi height, in;
    int t, k;
    void dfs(int u, int p = 0, int h = 0, ll d = 0) {
        up[0][u] = p, height[u] = h, dist[u] = d, in[u] = t++;
        for (auto [v, w] : adj[u]) if(v != p) {
            dfs(v, u, h + 1, d + w);
        }
    }
    LCA() {}
    LCA(const vector<vector<pair<int,ll>>> &_adj, const vll &_val) {
        adj = _adj;
        int n = sz(adj);
        k = 32 - __builtin_clz(n);
        up.assign(k, vi(n, 0));
        mini.assign(k, vll(n));
        height.resize(n);
        dist.resize(n);
        in.resize(n);
        t = 0;
        dfs(1);
        forn (i, k - 1) forn (j,n){
            up[i+1][j] = up[i][up[i][j]];
        }
        mini[0] = val = _val;
        forn (i, k - 1) forn (j, n) {
            mini[i+1][j] = min(mini[i][j], mini[i][up[i][j]]);
        }
    }
    int lca(int u, int v) {
        if (height[u] < height[v]) swap(u, v);
        int diff = height[u] - height[v];
        forn (i, k) if (diff >> i & 1) {
            u = up[i][u];
        }
        if (u == v) return u;
        dforn (i, k) if (up[i][u] != up[i][v]) {
            u = up[i][u], v = up[i][v];
        }
        return up[0][u];
    }
    ll get_dist(int u, int v) {
        return dist[u] + dist[v] - 2 * dist[lca(u,v)];
    }
    ll up_query(int u, int v){
        int diff = height[u] - height[v];
        ll ans = val[v];
        forn (i, k) if (diff >> i & 1) {
            ans = min(ans, mini[i][u]);
            u = up[i][u];
        }
        return ans;
    }
    ll query(int u, int v) {
        int l = lca(u,v);
        return min(up_query(u,l), up_query(v,l));
    }
};

struct VirtualTree {
    vi nodes;
    vector<vector<pair<int,ll>>> adj;
    LCA ds;
    map<int,int> pos;
    VirtualTree(const vi &_nodes, const vi &s, LCA &tree) {
        nodes = _nodes;
        auto cmp = [&](const int &u, const int &v) {
            return tree.in[u]<tree.in[v];
        };
        sort(all(nodes), cmp);
        int c = sz(nodes);
        nodes.reserve(2 * c);
        forn (i, c - 1) {
            nodes.pb(tree.lca(nodes[i], nodes[i + 1]));
        }
        sort(all(nodes), cmp);
        nodes.erase(unique(all(nodes)), end(nodes));
        c = sz(nodes);
        forn (i, c) {
            pos[nodes[i]] = i + 1;
        }
        adj.resize(c + 1);
        forn (i, c - 1) {
            int u = tree.lca(nodes[i], nodes[i+1]);
            ll w = tree.get_dist(u, nodes[i+1]);
            u = pos[u];
            adj[u].eb(i + 2, w);
            adj[i + 2].eb(u, w);
        }
        vll dist(c + 1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        forn (i, sz(s)) {
            int u = pos[s[i]];
            pq.emplace(dist[u] = 0, u);
        }
        while (!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if(dist[v] > d + w) pq.emplace(dist[v] = d + w, v);
            }
        }
        ds = LCA(adj, dist);
    }
    ll query(int u, int v) {
        u = pos[u], v = pos[v];
        return ds.get_dist(u, v) + 2 * ds.query(u, v);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, r;
    cin >> n >> r;
    vector<vi> nodes_of_color(r);
    forn (i,n) {
        int c; cin >> c; --c;
        nodes_of_color[c].pb(i+1);
    }
    vector<vector<pair<int,ll>>> adj(n + 1);
    forn (i, n - 1) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    vll val(n + 1,0);
    LCA tree(adj, val);
    vector<vi> nodes = nodes_of_color;
    forn (i, r) {
        nodes[i].pb(1);
    }
    int q;
    cin >> q;
    vector<vector<tuple<int,int,int>>> queries(r);
    forn (i, q) {
        int u, v, c;
        cin >> u >> v >> c; --c;
        queries[c].eb(u, v, i);
        nodes[c].pb(u);
        nodes[c].pb(v);
    }
    vll ans(q, -1);
    forn (i ,r) {
        if (nodes_of_color[i].empty()) continue;
        if (queries[i].empty()) continue;
        VirtualTree vt(nodes[i] ,nodes_of_color[i], tree);
        for (auto [u, v, id] : queries[i]) {
            ans[id] = vt.query(u,v);
        }
    }
    forn (i, q) cout << ans[i] << '\n';
    
    return 0;
}
