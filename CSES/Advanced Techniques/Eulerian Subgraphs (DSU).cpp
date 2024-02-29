#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
 
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
 
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    return true;
}
 
const int MOD = 1e9 + 7;
 
int mul(int a, int b) {
    return 1LL * a * b % MOD;
}
 
int binpow(int a, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    init(n);
    int backEdges = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (!unite(u - 1, v - 1)) {
            backEdges++;
        }
    }
    
    cout << binpow(2, backEdges) << '\n';
    
    return 0;
}