#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
int t[MAX_N], ans[MAX_N];
bitset<MAX_N> vis;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		--t[i];
	}
	
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int steps = 0;
        queue<int> path;
        int u = i;
        path.push(u);
        while (!vis[u]) {
            vis[u] = true;
            steps++;
            u = t[u];
            path.push(u);
        }
		steps += ans[u];
		bool cycle = false;
		while (!path.empty()) {
			if (path.front() == path.back()) {
                cycle = true;
            }
			ans[path.front()] = steps;
			if (!cycle) steps--;
			path.pop();
		}
	}
	
	for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
	cout << '\n';
	
	return 0;
}