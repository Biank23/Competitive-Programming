#include <bits/stdc++.h>
#include "doll.h"

using namespace std;

#define sz(x) int(x.size())
#define pb push_back

using vi = vector<int>;

vi L, R, v, state;
int stSize, skip, s;

void build(int u, int l, int r) {
    L.pb(0), R.pb(0), v.pb(0);
    if (r - l <= skip) {
        v[u] = -1;
        skip -= r-l;
        return;
    }
    if (r - l == 1) {
        return;
    }
    v[u] = --s;
    int m = (l + r) / 2;
    build(L[u] = stSize++, l, m);
    build(R[u] = stSize++, m, r);
}
     
void dfs(int u, int a) {
    if (u != 0 && v[u] == -1) {
        dfs(0, a);
    } else if (v[u] == 0) {
        v[u] = a;
    } else {
        state[u] ^= 1;
        if (state[u] == 1) dfs(L[u], a);
        else dfs(R[u], a);
    }
}
     
void create_circuit(int m, vi a) {
    vi c(m + 1), x, y;
    c[0] = a[0];
    int n = sz(a);
    if (n == 1) {
        return answer(c, x, y);
    }
    for (int i = 1; i <= m; i++) {
        c[i] = -1;
    }
    int sz = 1;
    while (sz < n) {
        sz *= 2;
    }
    skip = sz - n;
    stSize = 0;
    build(stSize++, 0, sz);
    a.pb(0), state.assign(stSize, 0);
    for (int i = 1; i <= n; i++) {
        dfs(0, a[i]);
    }
    for (int i = 0; i < stSize; i++) {
        if (L[i] != 0 || R[i] != 0) {
            x.pb(v[L[i]]);
            y.pb(v[R[i]]);
        }
    }
    answer(c, x, y);
}
