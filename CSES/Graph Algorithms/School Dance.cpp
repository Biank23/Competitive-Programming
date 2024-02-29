#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 501;
 
vector<int> adj[MAX_N];
bitset<MAX_N> vis;
int match[MAX_N], pairs = 0;
 
bool augPath(int u) {
    if (u == 0) {
        pairs++;
        return true;
    }
    if (vis[u]) {
        return false;
    }
    vis[u] = true;
    for (int v : adj[u]) {
        if (augPath(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++) {
        augPath(i);
        vis.reset();
    }
    
    cout << pairs << '\n';
    for (int i = 1; i <= m; i++) {
        if (match[i]) cout << match[i] << ' ' << i << '\n';
    }
    
    return 0;
}