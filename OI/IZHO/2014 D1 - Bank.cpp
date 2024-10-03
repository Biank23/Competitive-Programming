#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 20;
const int MAX_S = 1001;
 
int sum[1 << MAX_N];
bool vis[1 << MAX_N];
vector<int> adj[MAX_S];
int a[MAX_N], b[MAX_N], n;
 
bool dfs(int i, int u) {
    if (i == n) return true;
    vis[u] = true;
    for (int v : adj[a[i]]) {
        if ((u & v) == v && !vis[u ^ v] && dfs(i + 1, u ^ v)) return true;
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int mask = 1; mask < 1 << m; mask++) {
        if (mask != 0) {
            int i = __builtin_ctz(mask);
            sum[mask] = sum[mask ^ (1 << i)] + b[i];
        }
        if (sum[mask] < MAX_S) {
            adj[sum[mask]].push_back(mask);
        }
    }
    if (dfs(0, (1 << m) - 1)) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}