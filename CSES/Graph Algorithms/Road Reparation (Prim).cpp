#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9 + 7;
const int MAX_N = 2e5;
 
using ii = pair<int, int>;
using ll = long long;
 
vector<ii> adj[MAX_N];
bitset<MAX_N> done;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vector<int> dist(n, INF);
	pq.emplace(dist[0] = 0, 0);
	
	while (!pq.empty()) {
        auto [d, u] = pq.top();
		pq.pop();
        if (done[u]) continue;
		done[u] = true;
		for (auto [v, w] : adj[u]) {
			if (!done[v] && dist[v] > w) {
                pq.emplace(dist[v] = w, v);
            }
        }
	}
	
	bool flag = false;
	ll cost = 0;
	for (int i = 0; i < n; i++) {
		if (!done[i]) flag = true;
		cost += dist[i];
	}
	
	if (flag) cout << "IMPOSSIBLE\n";
	else cout << cost << '\n';
	
	return 0;
}
