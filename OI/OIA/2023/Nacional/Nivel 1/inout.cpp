#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;
using ii = pair<int, int>;

vi inout(vi &t, vi &e) {
    vector<ii> edge{{0, 1}};
    int n = sz(e);
    for (int i = 0; i < n; i++) {
        e[i]--;
        auto [A, B] = edge[e[i]];
        edge.emplace_back(A, i + 2);
        if (t[i] == 1) {
            edge[e[i]] = {i + 2, B};
        } else {
            edge.emplace_back(i + 2, B);
        }
    }
    vi g(n + 2, 0);
    for (auto [u, v] : edge) {
        g[u]++, g[v]--;
    }
    return g;
}
