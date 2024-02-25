#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
 
int st[2 * MAX_N], n;
 
void update(int i, int val) {
    st[i += n] = val;
    while (i /= 2) {
        st[i] = max(st[2 * i], st[2 * i + 1]);
    }
}
 
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res = max(res, st[l++]);
        if (r % 2 == 0) res = max(st[r--], res);
    }
    return res;
}
 
int par[MAX_N], depth[MAX_N], val[MAX_N];
int heavy[MAX_N], head[MAX_N], pos[MAX_N];
int sz[MAX_N], timer = 0;
vector<int> adj[MAX_N];
 
void dfs1(int u) {
    sz[u] = 1;
    int maxi = 0;
    for (int v : adj[u]) if (v != par[u]) {
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > maxi) {
            maxi = sz[v];
            heavy[u] = v;
        }
    }
}
 
void dfs2(int u, int h) {
    head[u] = h;
    pos[u] = timer++;
    update(pos[u], val[u]);
    if (heavy[u] != -1) {
        dfs2(heavy[u], h);
    }
    for (int v : adj[u]) {
        if(v != par[u] && v != heavy[u]) {
            dfs2(v, v);
        }
    }
}
 
void init() {
    memset(heavy, -1, sizeof heavy);
    dfs1(0);
    dfs2(0, 0);
}
 
int pathQuery(int a, int b) {
    int res = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] > depth[head[b]]) {
            swap(a, b);
        }
        res = max(res, query(pos[head[b]], pos[b]));
        b = par[head[b]];
    }
    if (depth[a] > depth[b]) {
        swap(a ,b);
    }
    res = max(res, query(pos[a], pos[b]));
    return res;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    init();
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(pos[a - 1], b);
        } else {
            cout << pathQuery(a - 1, b - 1) << ' ';
        }
    }
    cout << '\n';
}