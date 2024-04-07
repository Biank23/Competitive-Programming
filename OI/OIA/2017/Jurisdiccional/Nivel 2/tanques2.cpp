#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int MAX_N = 1e5;

using ii = pair<int, int>;

vector<int> orden;
vector<ii> adj[MAX_N];

void dfs(int u) {
    for (auto [d, v] : adj[u]) {
        dfs(v);
    }
    orden.push_back(u + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> w >> v;
        --u, --v;
        adj[u].emplace_back(w, v);
    }
    
    int k;
    cin >> k;
    --k;
    
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]), greater<ii>());
    }
    
    dfs(0);
    cout << orden[k] << " 1\n";
    
    return 0;
}
