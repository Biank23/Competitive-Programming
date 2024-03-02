#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2500;
const int INF = 1e9;
 
vector<int> adj[MAX_N];
 
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
    
    auto minCycle = [&](int s) {
        vector<int> dist(n, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        int minLength = INF;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                } else if (dist[v] >= dist[u]) {
                    minLength = min(minLength, dist[u] + 1 + dist[v]);
                }
            }
        }
        return minLength;
    };
    
    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, minCycle(i));
    }
    if (res == INF) cout << "-1\n";
    else cout << res << '\n';
    
    return 0;
}