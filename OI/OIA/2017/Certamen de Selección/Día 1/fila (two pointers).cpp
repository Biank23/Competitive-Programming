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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    sort(all(p), [&](const int &x, const int &y) {
        return orden[x] < orden[y];
    });
    vector<int> e(n, 0);
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        while (orden[i] < orden[p[j]]) {
            if (p[j] > i) {
                e[p[j]] = p[j] - i;
            }
            j--;
        }
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
