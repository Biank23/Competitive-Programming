#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

struct Fecha {
    int dia, mes, anno;
};

bool operator<(const Fecha &a, const Fecha &b) {
    return make_tuple(a.anno, a.mes, a.dia) > make_tuple(b.anno, b.mes, b.dia);
}

int fila(vector<Fecha> orden, vector<int> &enojados) {
    int n = sz(orden);
    vector<Fecha> pref(n);
    pref[0] = orden[0];
    for (int i = 1; i < n; i++) {
        pref[i] = min(pref[i - 1], orden[i]);
    }
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        int l = -1, r = i;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (pref[m] < orden[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        e[i] = i - r;
    }
    enojados.resize(n);
    for (int i = 0; i < n; i++) {
        enojados[i] = i;
    }
    sort(all(enojados), [&](const int &x, const int &y) {
        if (e[x] != e[y]) {
            return e[x] > e[y];
        }
        return x < y;
    });
    for (int i = 0; i < n; i++) {
        if (e[enojados[i]] == 0) {
            enojados.resize(i);
            break;
        }
        enojados[i]++;
    }
    return e[enojados.front() - 1];
}
