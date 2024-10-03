#include <bits/stdc++.h>
 
using namespace std;

#define sz(x) int(x.size())
 
const int MAX_N = 2e5;

using ll = long long;
using ii = pair<int, int>;

vector<int> adj[MAX_N];
int val[MAX_N], dist[MAX_N];

void dfs(int u, int p = -1, int d = 0) {
    d += val[u];
    dist[u] = d;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u, d);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 2) {
        cout << "0\n";
        return 0;
    }
    for (int u = 0; u < n; u++) {
        val[u] = sz(adj[u]) - 2;
    }
    int s = 0;
    while (val[s] == -1) s++;
    for (int t = 2; t --> 0;) {
        dfs(s);
        for (int u = 0; u < n; u++) {
            if (dist[u] > dist[s]) s = u;
        }
    }
    int res = dist[s];
    bool flag = false;
    for (int u = 0; u < n; u++) {
        if (dist[u] == res && val[u] != res) flag = true;
        if (val[u] == res) {
            for (int v : adj[u]) if (val[v] == 0) flag = true;
        }
    }
    res += 2;
    if (!flag) res--;
    cout << res << '\n';
    
    return 0;
}