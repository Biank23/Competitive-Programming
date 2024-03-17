#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5, MAX_K = 18;
 
int up[MAX_K][MAX_N];
 
void init(int n) {
    for (int i = 1; i < MAX_K; i++) {
        for (int j = 0; j < n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
}
 
int jump(int x, int k) {
    for (int i = 0; i < MAX_K; i++) {
        if (k>>i&1) x = up[i][x];
    }
    return x;
}
 
int d[MAX_N];
bitset<MAX_N> vis;
 
void dfs(int u) {
    vis[u] = true;
    int v = up[0][u];
    if (!vis[v]) dfs(v);
    d[u] = d[v] + 1;
}
 
int check(int u, int v) {
    int dist = d[u] - d[v];
    if (dist >= 0 && jump(u, dist) == v) {
        return dist;
    }
    return -1;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    for (int i = 0; i < n; i++) {
        cin >> up[0][i];
        --up[0][i];
    }
    init(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int res = check(u, v);
        if (res == -1) {
            res = check(jump(u, d[u]), v);
            if (res != -1) res += d[u];
        }
        cout << res << '\n';
    }
 
    return 0;
}