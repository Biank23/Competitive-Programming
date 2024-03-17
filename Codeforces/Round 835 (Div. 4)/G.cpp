#include "bits/stdc++.h"

using namespace std;
 
using ii = pair<int, int>;

const int MAX_N = 1e5 + 9;

vector<ii> adj[MAX_N];
set<int> s;

int n, a, b;

void dfs1(int u, int p = -1, int x = 0) {
    if (u == b) return;
    s.insert(x);
    for (auto [v, w] : adj[u]) {
        if (v != p) dfs1(v, u, x ^ w);
    }
}

bool dfs2(int u, int p = -1, int x = 0) {
    if (u != b && s.count(x)) return true;
    for (auto [v, w] : adj[u]) {
        if (v != p && dfs2(v, u, x ^ w)) return true;
    } 
    return false;
}

void clear() {
    s.clear();
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
}  
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        cin >> n >> a >> b;
        --a, --b;
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        dfs1(a);
        if (dfs2(b)) cout << "YES\n";
        else cout << "NO\n";
        clear();
    }
    
    return 0;
}
