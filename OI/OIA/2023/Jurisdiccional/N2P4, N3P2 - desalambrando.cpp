#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
using vi = vector<int>;

struct DSU {
    vi parent;
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[x] = y;
        return true;
    }
};

using Edge = tuple<int, int, int>;

ll desalambrando(int N, vi &a, vi &b, vi &costo) {
    int M = sz(a);
    vector<Edge> graph(M);
    for (int i = 0; i < M; i++) {
        graph[i] = {costo[i], a[i] - 1, b[i] - 1};
    }
    sort(all(graph), greater<Edge>());
    ll ans = 0;
    DSU dsu(N);
    for (auto [w, u, v] : graph) {
        if (!dsu.unite(u, v)) ans += w;
    }
    return ans;
}
