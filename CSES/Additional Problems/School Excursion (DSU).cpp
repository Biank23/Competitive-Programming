#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5 + 9;
 
int par[MAX_N], sz[MAX_N];
 
void init(int n) {
    for (int i = 0; i < n; i++) {
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
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}
 
bitset<MAX_N> dp;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u - 1, v - 1);
    }
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (par[i] == i) {
            dp |= dp << sz[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i];
    }
    
    return 0;
}