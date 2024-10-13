#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int T = 1 << 18;

long long st[2 * T], lazy[2 * T];

void propagar(int u) {
    if (u < T) {
        lazy[2 * u] += lazy[u];
        lazy[2 * u + 1] += lazy[u];
    }
    st[u] += lazy[u];
    lazy[u] = 0;
}

void actualizar(int ini, int fin, int valor, int izq = 0, int der = T, int u = 1) {
    propagar(u);
    if (ini <= izq && der <= fin) {
        lazy[u] = valor;
        return propagar(u);
    }
    if (fin <= izq || der <= ini) return;
    int med = (izq + der) / 2;
    actualizar(ini, fin, valor, izq, med, 2 * u);
    actualizar(ini, fin, valor, med, der, 2 * u + 1);
    st[u] = max(st[2 * u], st[2 * u + 1]);
}

long long consulta(int ini, int fin, int izq = 0, int der = T, int u = 1) {
    propagar(u);
    if (ini <= izq && der <= fin) return st[u];
    if (fin <= izq || der <= ini) return 0;
    int med = (izq + der) / 2;
    return max(consulta(ini, fin, izq, med, 2 * u), consulta(ini, fin, med, der, 2 * u + 1));
}

vector<long long> pomelos(int N, vector<string> &e, vector<int> &p1, vector<int> &p2) {
    vector<int> A(N, 0), B(N, 0);
    vector<long long> respuesta;
    for (int i = 0; i < int(e.size()); i++) {
        p1[i]--;
        if (e[i] == "C") {
            int l = p1[i], r = p2[i];
            long long res = consulta(l, r);
            if (l > 0) res -= consulta(l - 1, l) - B[l - 1];
            respuesta.push_back(res);
        } else {
            int j = p1[i], v = p2[i];
            if (e[i] == "A") {
                actualizar(j, N, v - A[j]);
                A[j] = v;
            } else {
                actualizar(j, j + 1, v - B[j]);
                B[j] = v;
            }
        }
    }
    return respuesta;
}