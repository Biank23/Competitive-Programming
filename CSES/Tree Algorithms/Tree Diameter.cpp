#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N];
 
ii dfs(int u, int p = -1) {
    ii maxDist = {0, u};
    for (int v : adj[u]) if (v != p) {
        auto [dist, node] = dfs(v, u);
        maxDist = max(maxDist, {dist + 1, node});
    }
    return maxDist;
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
    auto [_, node] = dfs(0);
    auto [dist,__] = dfs(node);
    cout << dist << '\n';
    
    return 0;
}