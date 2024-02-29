#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int MAX_N = 2e5;
 
bool vis[MAX_N];
queue<ii> adj[MAX_N];
int deg[MAX_N];
queue<int> path;
 
void dfs(int u) {
	while (!adj[u].empty()) {
		auto [v, i] = adj[u].front();
		adj[u].pop();	
		if (!vis[i]) {
            vis[i] = true;
            dfs(v);
        }
	}
	path.push(u + 1);
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
		adj[u].emplace(v, i);
		adj[v].emplace(u, i);
        deg[u]++, deg[v]++;
	}
    
    bool flag = true;
    for (int i = 0; i < n; i++) {
        flag &= deg[i] % 2 == 0;
    }
	
	if (flag) dfs(0);
	
	if (ssize(path) != m+1) {
		cout << "IMPOSSIBLE\n";
	} else {
        while (!path.empty()) {
            cout << path.front() << ' ';
            path.pop();
        }
 	}
	
	return 0;
}