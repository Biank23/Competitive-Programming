#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
const int MAX_N = 2e5;
 
queue<int> adj[MAX_N];
vector<int> path;
int in[MAX_N], out[MAX_N];
 
void dfs(int u) {
	while (!adj[u].empty()) {
		auto v = adj[u].front();
		adj[u].pop();	
		dfs(v);
	}
	path.push_back(u + 1);
}
 
bool check(int n) {
    for (int i = 1; i < n - 1; i++) {
        if (out[i] != in[i]) return false;
    }
	return out[0] == in[0] + 1 && out[n - 1] == in[n - 1] - 1;
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
		adj[u].push(v);
		out[u]++, in[v]++;
	}
	
	if (check(n)) dfs(0);
	
    reverse(all(path));
	if (ssize(path) != m + 1 || path.back() != n) {
		cout << "IMPOSSIBLE\n";
	} else {
        for (int u : path) {
            cout << u << ' ';
        }
 	}
	
	return 0;
}
