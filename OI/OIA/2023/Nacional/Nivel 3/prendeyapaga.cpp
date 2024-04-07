#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;

const int MAX_N = 1e5 + 9;

struct FTree {
    int ft[MAX_N];
    void update(int i, int v) {
        for (i++; i < MAX_N; i += i&-i) {
            ft[i] += v;
        }
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i&-i) {
            s += ft[i];
        }
        return s;
    }
    int query(int l, int r) {
        return query(r) - query(l);
    }
};

vi adj[MAX_N];
int in[MAX_N], out[MAX_N], t = 1;

void dfs(int u, int p = -1) {
    in[u] = t++;
    for (int v : adj[u]) {
        if(v != p) dfs(v, u);
    }
    out[u] = t;
}

bool state[MAX_N];

FTree subtrees, paths;

void update(int u, int v) {
    state[u] ^= 1;
    subtrees.update(in[u], v);
    paths.update(in[u], v);
    paths.update(out[u], -v);
}

int setwifi(int u) {
    if (subtrees.query(in[u], out[u]) ||
        paths.query(in[u] + 1)) {
        return 0;
    }
    update(u, 1);
    return 1;
}

int setrt(int u) {
    if (!state[u]) {
        return 0;
    }
    update(u, -1);
    return 1;
}

vi hoteles(vi &padre, vi &tipo, vi &nodo) { 
    for (int i = 0; i < sz(padre); i++) {
        adj[padre[i]].push_back(i + 1);
    }
    dfs(0);
    int q = sz(tipo);
    vi ans(q);
    for (int i = 0; i < q; i++) {
        if (tipo[i]) ans[i] = setrt(nodo[i]);
        else ans[i] = setwifi(nodo[i]);
    }
    return ans;
}
