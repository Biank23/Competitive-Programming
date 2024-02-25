#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
using ll = long long;
 
vector<int> adj[MAX_N];
ll down[MAX_N], ans[MAX_N];
int sz[MAX_N];
 
void dfsDown(int u, int p = -1) {
    down[u] = 0;
    sz[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dfsDown(v, u);
        down[u] += down[v] + sz[v];
        sz[u] += sz[v];
    }
}
 
void dfsUp(int u, int p = -1, ll upVal = 0, int upSize = 0) {
    ans[u] = down[u] + upVal + upSize;
    upSize += sz[u];
    for (int v : adj[u]) if (v != p) {
        dfsUp(v, u, ans[u] - down[v] - sz[v], upSize - sz[v]);
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
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
