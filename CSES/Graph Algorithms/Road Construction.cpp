#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
int par[MAX_N], sz[MAX_N];
int components, maxSize;
 
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i, sz[i] = 1;
    }
    components = n, maxSize = 1;
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
    components--;
    maxSize = max(maxSize, sz[x]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    init(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        --from, --to;
        unite(from, to);
        cout << components << ' ' << maxSize << '\n';
    }
    
    return 0;
}