#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int MAX_N = 1e5;

using ll = long long;
using ii = pair<int, int>;

vector<ll> orden;
vector<ii> adj[MAX_N];
int c[MAX_N];
ll water = 0;

void dfs(int u) {
    orden.push_back(water + 1);
    int prev = c[u];
    for (auto [d, v] : adj[u]) {
        water += prev - d;
        dfs(v);
        prev = d;
    }
    water += prev;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> w >> v;
        --u, --v;
        adj[u].emplace_back(w, v);
    }
    
    
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]), greater<ii>());
    }
    
    dfs(0);
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << upper_bound(all(orden), k) - begin(orden) << ' ';
    }
    cout << '\n';
    
    return 0;
}
