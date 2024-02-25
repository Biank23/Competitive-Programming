#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
 
using ll = long long;
 
ll st[2 * MAX_N];
int n;
 
void update(int i, int val) {
    st[i += n] = val;
    while (i /= 2) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
}
 
ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res += st[l++];
        if (r % 2 == 0) res += st[r--];
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
 
ll pathQuery(int b) {
    ll res = 0;
    while (head[b] != 0) {
        res += query(pos[head[b]], pos[b]);
        b = par[head[b]];
    }
    res += query(0, pos[b]);
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
        int t, a;
        cin >> t >> a;
        if (t == 1) {
            int b;
            cin >> b;
            update(pos[a - 1], b);
        } else {
            cout << pathQuery(a - 1) << '\n';
        }
    }
}