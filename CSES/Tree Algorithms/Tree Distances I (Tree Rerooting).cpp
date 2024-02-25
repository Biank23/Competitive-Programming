#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N];
int down[MAX_N], up[MAX_N];
 
int dfsDown(int u, int p = -1) {
    down[u] = 0;
    for (int v : adj[u]) if (v != p) {
        down[u] = max(down[u], dfsDown(v, u) + 1);
    }
    return down[u];
}
 
void dfsUp(int u, int p = -1, int upVal = 0) {
    up[u] = upVal;
    
    int m = ssize(adj[u]);
    vector<int> prefix(m + 1);
    prefix[0] = 0;
    for (int i = 0; i < m; i++) {
        int v = adj[u][i];
        if (v != p) {
            prefix[i + 1] = max(prefix[i], down[v] + 1);
        } else {
            prefix[i + 1] = prefix[i];
        }
    }
    vector<int> suffix(m + 1);
    suffix[m] = 0;
    for (int i = m - 1; i >= 0; i--) {
        int v = adj[u][i];
        if (v != p) {
            suffix[i] = max(suffix[i + 1], down[v] + 1);
        } else {
            suffix[i] = suffix[i + 1];
        }
    }
    for (int i = 0; i < m; i++) {
        int v = adj[u][i];
        if (v != p) {
            dfsUp(v, u, max({upVal, prefix[i], suffix[i + 1]}) + 1);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsDown(0);
    dfsUp(0);
    for (int i = 0; i < n; i++) {
        cout << max(down[i], up[i]) << ' ';
    }
    cout << '\n';
    
    return 0;
}