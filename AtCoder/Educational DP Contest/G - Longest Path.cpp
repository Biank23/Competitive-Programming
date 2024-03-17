#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5;

vector<int> adj[MAX_N];
int dp[MAX_N], deg[MAX_N];

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
        ++deg[v];
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) q.push(i);
    }
    
    int res = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            --deg[v];
            if (!deg[v]) {
                res = max(res, dp[v]);
                q.push(v);
            }
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
