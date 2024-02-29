#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
 
#define all(x) begin(x), end(x)
 
const int MAX_N = 1e5 + 9;
 
bitset<MAX_N> vis;
ll dp[MAX_N], val[MAX_N], k[MAX_N];
 
void topsort(int u, vector<vi> &adj, vi &order) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) topsort(v, adj, order);
    }
    order.push_back(u);
} 
 
void paint(int u, vector<vi> &adj, vi &cmp, int color) {
    cmp[u] = color;
    val[color] += k[u];
    for (int v : adj[u]) {
        if (!cmp[v]) paint(v, adj, cmp, color);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    vector<vi> adj(n), adjT(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    
    vi order;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) topsort(i, adj, order);
    }
    
    reverse(all(order));
    vi cmp(n, 0);
    int color = 1;
    for (int i : order) {
        if (!cmp[i]) {
            paint(i, adjT, cmp, color);
            color++;
        }
    }
    
    vector<vi> adjC(color);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) if (cmp[u] != cmp[v]) {
            adjC[cmp[u]].push_back(cmp[v]);
        }
    }
    
    vis.reset(), order.clear();
    for (int i = 1; i < color; i++) {
        if (!vis[i]) topsort(i, adjC, order);
    }
    
    ll res = 0;
    for (int u : order) {
        dp[u] = val[u];
        for (int v : adjC[u]) {
            dp[u] = max(dp[u], dp[v] + val[u]);
        }
        res = max(res, dp[u]);
    }
    
    cout << res << '\n';
    
    return 0;
}
