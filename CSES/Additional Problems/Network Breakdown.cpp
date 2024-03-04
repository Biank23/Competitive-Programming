#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
 
using ii = pair<int, int>;
 
int par[MAX_N], sz[MAX_N], components;
 
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i, sz[i] = 1;
    }
    components = n;
}
 
int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}
 
void unite(ii p) {
    auto [x, y] = p;
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
    components--;
}
 
void read(vector<ii> &e) {
    for (auto &[u, v] : e) {
        cin >> u >> v;
        --u, --v;
        if (u > v) swap(u, v);
    }
}
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<ii> edges(m), breakdown(k);
    read(edges);
    read(breakdown);
    
    set<ii> breaks(all(breakdown));
    init(n);
    for (ii e : edges) {
        if (!breaks.count(e)) unite(e);
    }
    
    vector<int> res(k);
    for (int i = k - 1; i >= 0; i--) {
        res[i] = components;
        unite(breakdown[i]);
    }
    
    for (int c : res) {
        cout << c << ' ';
    }
    
    return 0;
}