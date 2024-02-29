#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 18;
const int MOD = 1e9 + 7;
 
int dp[MAX_N][1<<MAX_N];
vector<int> adj[MAX_N + 2];
 
void add(int &x, int v) {
    x += v;
    if (x >= MOD) x -= MOD;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	n -= 2;
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u -= 2, v -= 2;
        if (v != -1 && u != n) {
            adj[v].push_back(u);
        }
	}
	
    for (int mask = 1; mask < 1<<n; mask++) {
        for (int u = 0; u < n; u++) if (mask>>u&1) {
            for (int v : adj[u]) {
                if (v == -1) {
                    if (mask == 1<<u) add(dp[u][mask], 1);
                } else if (mask>>v&1) {
                    add(dp[u][mask], dp[v][mask ^ (1<<u)]);
                }
            }
        }
    }
    
    int res = 0;
    for (int u : adj[n]) {
        if (u == -1) {
            if (n == 0) add(res, 1);
        } else {
            add(res, dp[u][(1<<n) - 1]);
        }
    }
	
	cout << res << '\n';
	
	return 0;
}