#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;

const int MAX_N = 1e4 + 9;

vi adj[MAX_N];
bitset<MAX_N> vis;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int indeg[MAX_N];

void print(vector<int> &v) {
    if (v.empty()) {
        cout << "0\n";
        return;
    }
    for (int &a : v) {
        cout << a << ' ';
    }
    cout << '\n';
}

int main() {
    freopen("arbol.in", "r", stdin);
	freopen("arbol.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    
    vi roots, many, notVisited;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) roots.push_back(i);
        if (indeg[i] > 1) many.push_back(i);
    }
    if (sz(roots) == 1) {
        dfs(roots.front());
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) notVisited.push_back(i);
        }
    }
    
    if (sz(roots) == 1 && many.empty() && notVisited.empty()) {
        cout << "Si " << roots.front() << '\n';
    } else {
        cout << "No\n";
        print(roots);
        print(many);
        print(notVisited);
    }
    
    return 0;
}
