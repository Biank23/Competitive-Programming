#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
 
int ft[MAX_N];
 
inline int lsb(int i) {
    return i & -i;
}
 
void update(int i, int v) {
    while (i < MAX_N) {
        ft[i] += v;
        i += lsb(i);
    }
}
 
int query(int i) {
    int res = 0;
    while (i > 0) {
        res += ft[i];
        i -= lsb(i);
    }
    return res;
}
 
int val[MAX_N], ans[MAX_N];
vector<int> adj[MAX_N];
int in[MAX_N], out[MAX_N], timer = 0;
map<int, int> pos;
 
void dfs(int u, int p = -1) {
    in[u] = ++timer;
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    out[u] = timer;
    
    update(out[u], 1);
    if (pos.count(val[u])) {
        update(pos[val[u]], -1);
    }
    pos[val[u]] = out[u];
    ans[u] = query(out[u]) - query(in[u] - 1);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    
    return 0;
}