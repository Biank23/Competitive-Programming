#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int INF = 2e9;

struct Artefact {
    int w, a, b;
    bool operator<(const Artefact &o) {
        return w < o.w;
    }
};

struct Block {
    ll sumB;
    int minEven, minOdd, minVal, size;
    Block() {}
    Block(Artefact x) {
        sumB = x.b;
        minEven = x.a;
        minOdd = minVal = INF;
        size = 1;
    }
    ll getCost() {
        if (size % 2 == 0) return sumB;
        return sumB + min(minEven, minVal);
    }
};

struct DSU {
    vector<Block> v;
    vi par;
    ll res;
    DSU(vector<Artefact> &x) {
        int n = sz(x);
        v.resize(n);
        par.resize(n);
        iota(all(par), 0);
        res = 0;
        for (int i = 0; i < n; i++) {
            v[i] = x[i];
            res += v[i].getCost();
        }
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int i) {
        int x = find(i), y = find(i + 1);
        if (x != y) {
            res -= v[x].getCost();
            res -= v[y].getCost();
            v[x].sumB += v[y].sumB;
            if (v[x].size % 2 == 0) {
                v[x].minEven = min(v[x].minEven, v[y].minEven);
                v[x].minOdd = min(v[x].minOdd, v[y].minOdd);
            } else {
                v[x].minEven = min(v[x].minEven, v[y].minOdd);
                v[x].minOdd = min(v[x].minOdd, v[y].minEven);
            }
            v[x].minVal = min(v[x].minVal, v[y].minVal);
            par[y] = x;
            v[x].size += v[y].size;
            res += v[x].getCost();
        }
    }
    void update(int i, int val) {
        int b = find(i);
        assert(b == find(i + 2));
        res -= v[b].getCost();
        v[b].minVal = min(v[b].minVal, val);
        res += v[b].getCost();
    }
};

vector<ll> calculate_costs(vi W, vi A, vi B, vi E) {
    int n = sz(W), q = sz(E);
    vector<Artefact> v(n);
    for (int i = 0; i < n; i++) {
        v[i].w = W[i];
        v[i].a = A[i] - B[i];
        v[i].b = B[i];
    }
    sort(all(v));
    DSU dsu(v);
    vi p(q); iota(all(p), 0);
    sort(all(p), [&](const int &x, const int &y) {
        return E[x] < E[y];
    });
    vi o[2];
    for (int i = 0; i < 2; i++) {
        o[i].resize(n - 1 - i);
        iota(all(o[i]), 0);
        sort(all(o[i]), [&](const int &x, const int &y) {
            return v[x + 1 + i].w - v[x].w < v[y + 1 + i].w - v[y].w;
        });
    }
    int j[2] = {0, 0};
    vector<ll> res(q);
    for (int i : p) {
        int D = E[i];
        for (int k = 0; k < 2; k++) {
            while (j[k] < sz(o[k])) {
                int x = o[k][j[k]];
                if (v[x + 1 + k].w - v[x].w > D) break;
                if (k == 0) dsu.unite(x);
                else dsu.update(x, v[x + 1].a);
                j[k]++;
            }
        }
        cerr << '\n';
        res[i] = dsu.res;
    }
    return res;
}
