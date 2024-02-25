#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N];
int distToRoot[MAX_N];
int distToDiameter[2][MAX_N];
 
void dfs(int dist[], int u, int p = -1, int h = 0) {
    dist[u] = h;
    for (int v : adj[u]) if (v != p) {
        dfs(dist, v, u, h + 1);
    }
}
 
ii findMaxDist(int dist[], int n) {
    ii maxDist = {-1, -1};
    for (int i = 0; i < n; i++) {
        maxDist = max(maxDist, {dist[i], i});
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
    dfs(distToRoot, 0);
    auto [_, A] = findMaxDist(distToRoot, n);
    dfs(distToDiameter[0], A);
    auto [__,B] = findMaxDist(distToDiameter[0], n);
    dfs(distToDiameter[1], B);
    
    for (int i = 0; i < n; i++) {
        cout << max(distToDiameter[0][i], distToDiameter[1][i]) << ' ';
    }
    
    return 0;
}
