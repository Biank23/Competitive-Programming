#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using vi = vector<int>;
 
const int MAX_N = 5e4 + 9;
 
bitset<MAX_N> vis;

void topsort(int u, const vector<vi> &adj, vi &order) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) {
        topsort(v, adj, order);
    }
    order.push_back(u);
}
 
void paint(int u, const vector<vi> &adj, vi &comp, int color) {
    comp[u] = color;
    for (int v : adj[u]) if (!comp[v]) {
        paint(v, adj, comp, color);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
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
    vi comp(n, 0);
    int color = 1;
    for (int i : order) {
        if (!comp[i]) paint(i, adjT, comp, color++);
    }
    
    const int k = color;
    vector<vi> adjC(k);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) if (comp[u] != comp[v]) {
            adjC[comp[u]].push_back(comp[v]);
        }
    }
    
    vis.reset(), order.clear();
    for (int i = 1; i < k; i++) {
        if (!vis[i]) topsort(i, adjC, order);
    }
    
    vi cant(k, 0);
    for (int u = 0; u < n; u++) {
        cant[comp[u]]++;
    }
    
    vi dp(k, 0);
    for (int u : order) {
        dp[u] = cant[u];
        for (int v : adjC[u]) {
            dp[u] += dp[v];
        }
    }
    
    for (int u = 0; u < n; u++) {
        cout << dp[comp[u]] - 1 << '\n';
    }
    
    return 0;
}