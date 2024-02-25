#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
int sz[MAX_N];
vector<int> adj[MAX_N];
int n, centroid = -1;
 
void dfs(int u, int p = -1) {
    bool flag = true;
    sz[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        flag &= (sz[v] <= n / 2);
        sz[u] += sz[v];
    }
    flag &= (n - sz[u] <= n / 2);
    if (flag) {
        centroid = u + 1;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    assert(centroid != -1);
    cout << centroid << '\n';
 
    return 0;
}