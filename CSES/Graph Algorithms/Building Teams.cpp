#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5 + 9;
 
vector<int> adj[MAX_N];
int team[MAX_N];
bool possible = true;
 
void dfs(int u, int t = 1) {
    team[u] = t;
    for (int v : adj[u]) {
        if (!team[v]) {
            dfs(v, 3 - t);
        } else if (team[v] == t) {
            possible = false;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 0; i < n; i++) {
        if (!team[i]) dfs(i);
    }
    
    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        cout << team[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}