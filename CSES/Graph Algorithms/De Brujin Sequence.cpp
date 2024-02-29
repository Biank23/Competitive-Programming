#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 14;
 
queue<int> adj[1<<MAX_N];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	--n;
	
	if (n == 0) {
		cout << "01";
		return 0;
	}
	
    int N = 1<<n;
	for (int u = 0; u < N; u++) {
        int v = u<<1;
        if (v >= N) v -= N;
        adj[u].push(v);
        adj[u].push(v ^ 1);
    }
	
	stack<int> s;
    s.push(0);
	string ans = "";
	while (!s.empty()) {
		int u = s.top();
		if (!adj[u].empty()) {
			int v = adj[u].front();
			adj[u].pop();
			s.push(v);
		} else {
			ans += char('0' + u&1);
			s.pop();
		}
	}
	ans += string(n - 1, '0');
	cout << ans << '\n';
	
	return 0;
}