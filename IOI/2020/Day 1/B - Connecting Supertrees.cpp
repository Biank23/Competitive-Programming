#include "supertrees.h"
#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;

struct DSU {
    vi par;
    DSU(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
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
        par[x] = y;
        return true;
    }
};

int construct(vector<vi> p) {
    int n = sz(p);
    vector<vi> b(n, vi(n, 0));
    DSU dsu(n), dsuCmp(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i][j] != 0) {
                dsuCmp.unite(i, j);
            }
            if (p[i][j] == 1) {
                b[i][j] = b[j][i] = dsu.unite(i, j);
            }
        }
    }
    
    vector<set<int>> groups(n);
    for (int i = 0; i < n; i++) {
        groups[dsuCmp.find(i)].insert(dsu.find(i));
    }
    
    for (int i = 0; i < n; i++) {
        vi g(all(groups[i]));
        int m = sz(g);
        if (m < 2) continue;
        if (m == 2) return false;
        auto next = [&](int j) {
            if (++j == m) j = 0;
            return j;
        };
        for (int j = 0; j < m; j++) {
            b[g[j]][g[next(j)]] = b[g[next(j)]][g[j]] = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i][j] != 1 && dsu.find(i) == dsu.find(j)) {
                return false;
            }
            if (p[i][j] != 2 && p[i][j] != 0 && dsu.find(i) != dsu.find(j)) {
                return false;
            }
            if (p[i][j] == 0 && dsuCmp.find(i) == dsuCmp.find(j)) {
                return false;
            }
        }
    }
    
    build(b);
    return true;
}
