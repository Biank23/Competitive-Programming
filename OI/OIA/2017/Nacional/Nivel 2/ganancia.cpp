#include <bits/stdc++.h>

using namespace std;

struct PQ {
    int precio, cantidad;
};

using ii = pair<int, int>;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

const int INF = 1e9 + 20;

int ganancia(int P, vector<PQ> fabricantes, vector<PQ> compradores, int &Fab, int &Comp) {
    vector<pair<PQ, int>> f, c;
    for (int i = 0; i < sz(fabricantes); i++) {
        f.emplace_back(fabricantes[i], i + 1);
    }
    for (int i = 0; i < sz(compradores); i++) {
        c.emplace_back(compradores[i], i + 1);
    }
    auto cmp = [](const pair<PQ, int> &lhs, const pair<PQ, int> &rhs) {
        return lhs.first.cantidad < rhs.first.cantidad;
    };
    sort(all(f), cmp);
    sort(all(c), cmp);
    int j = 0;
    Fab = 0, Comp = 0;
    ii fabricante = {INF, 0};
    int mejor = -1;
    auto actualizarRespuesta = [&](int i, int costo) {
        int ganancia = -1;
        if (costo <= P) {
            ganancia = c[i].first.cantidad * c[i].first.precio - costo;
        }
        if (ganancia > mejor) {
            mejor = ganancia;
            Comp = c[i].second;
            Fab = fabricante.second;
        }
    };
    for (int i = 0; i < sz(c); i++) {
        while (j < sz(f) && f[j].first.cantidad <= c[i].first.cantidad) {
            fabricante = min(fabricante, {f[j].first.precio, f[j].second});
            j++;
        }
        if (fabricante.first < INF) {
            actualizarRespuesta(i, c[i].first.cantidad * fabricante.first);
        }
    }
    j = sz(f) - 1;
    fabricante = {INF, 0};
    for (int i = sz(c) - 1; i >= 0; i--) {
        while (j >= 0 && f[j].first.cantidad > c[i].first.cantidad) {
            fabricante = min(fabricante, {f[j].first.precio * f[j].first.cantidad, f[j].second});
            j--;
        }
        if (fabricante.first < INF) {
            actualizarRespuesta(i, fabricante.first);
        } 
    }
    return mejor;
}
