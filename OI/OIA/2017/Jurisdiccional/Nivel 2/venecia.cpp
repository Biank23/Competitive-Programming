#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int MAX_N = 1e5;
const int MAX_M = 3e5;

using ii = pair<int, int>;

bitset<MAX_M> vis;
vector<ii> adj[MAX_N];
vector<int> ans;

void dfs(int u) {
    for (auto [v, i] : adj[u]) {
        if (!vis[i]) {
            vis[i] = true;
            ans.push_back(i);
            dfs(v);
            ans.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, s;
    cin >> n >> m >> s;
    --s;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    
    dfs(s);
    
    cout << sz(ans) << '\n';
    for (int i : ans) cout << i + 1 << ' ';
    cout << '\n';
    
    return 0;
}
