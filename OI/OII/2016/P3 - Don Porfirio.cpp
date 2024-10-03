#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int MAX_N = 1e5 + 9;

int par[MAX_N], sz[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i, sz[i] = 1;
    }
}

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

const int MOD = 1e9 + 7;

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    int cant = mul(sz[x], sz[y]);
    par[x] = y;
    sz[y] += sz[x];
    return cant;
}

struct Edge {
    int u, v, w;
    bool operator<(const Edge &o) {
        return w < o.w;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    init(n);
    vector<Edge> tree(n - 1);
    for (auto &[u, v, w] : tree) {
        cin >> u >> v >> w;
        --u, --v;
    }
    sort(all(tree));
    int ans = 0;
    for (auto [u, v, w] : tree) {
        ans += mul(w, unite(u, v));
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
    
    return 0;
}