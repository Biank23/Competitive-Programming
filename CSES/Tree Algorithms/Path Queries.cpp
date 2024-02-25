#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
 
using ll = long long;
 
ll ft[MAX_N];
 
inline int lsb(int i) {
    return i & -i;
}
 
void update(int i, int v) {
    while (i < MAX_N) {
        ft[i] += v;
        i += lsb(i);
    }
}
 
ll query(int i) {
    ll res = 0;
    while (i > 0) {
        res += ft[i];
        i -= lsb(i);
    }
    return res;
}
 
int val[MAX_N];
vector<int> adj[MAX_N];
int in[MAX_N], out[MAX_N], timer = 0;
 
void dfs(int u, int p = -1) {
    in[u] = ++timer;
    update(in[u], val[u]);
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    out[u] = timer;
    update(out[u] + 1, -val[u]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0);
    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;
        --x;
        if (t == 1) {
            int y;
            cin >> y;
            update(in[x], y - val[x]);
            update(out[x] + 1, val[x] - y);
            val[x] = y;
        } else {
            cout << query(in[x]) << '\n';
        }
    }
    
    return 0;
}