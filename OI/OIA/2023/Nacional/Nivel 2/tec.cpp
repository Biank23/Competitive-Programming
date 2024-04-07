#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;

const int MAX_N = 1e4;

int p[MAX_N];
vi adj[MAX_N];
bitset<MAX_N> c;

int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    p[x] = y;
    return true;
}

void tablero(int N, vi &A, vi &B) {
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    for (int i = 0; i < sz(A); i++) {
        int u = A[i] - 1, v = B[i] - 1;
        if (unite(u, v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}

void marcar(vi &v, bool b) {
    for (int &x : v) c[x] = b;
}

int con_quien_comercio(vi &controlados) {
    for (int &u : controlados) --u;
    marcar(controlados, true);
    for (int &u : controlados) {
        for (int &v : adj[u]) {
            if (!c[v]) {
                marcar(controlados, false);
                return v + 1;
            }
        }
    }
    return -1;
}
