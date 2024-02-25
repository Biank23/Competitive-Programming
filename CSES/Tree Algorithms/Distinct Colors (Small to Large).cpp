#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
const int MAX_N = 2e5;
 
int ans[MAX_N];
vector<int> adj[MAX_N];
set<int> s[MAX_N];
 
void dfs(int u, int p = -1) {
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		if (ssize(s[v]) > ssize(s[u])) {
			swap(s[u], s[v]);
		}
		s[u].insert(all(s[v]));
	}
	ans[u] = ssize(s[u]);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
        cin >> c;
		s[i].insert(c);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0);
	for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
	
	return 0;
}