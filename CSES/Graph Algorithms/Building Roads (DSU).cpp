#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5 + 9;
 
int par[MAX_N], sz[MAX_N];
 
void init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i, sz[i] = 1;
    }
}
 
int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}
 
void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[y] > sz[x]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }
    
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (par[i] == i) v.push_back(i);
    }
    
    cout << ssize(v) - 1 << '\n';
    for (int i = 1; i < ssize(v); i++) {
        cout << v[i - 1] << ' ' << v[i] << '\n';
    }
    
    return 0;
}