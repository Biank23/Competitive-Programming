#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;

int fabricante(int P, int precioVenta, int cantidadVenta, vi precioCompra, vi cantidadCompra, int &fabricante) {
    fabricante = 0;
    int mejor = -1;
    int n = sz(cantidadCompra);
    for (int i = 0; i < n; i++) {
        int costo = precioCompra[i] * max(cantidadCompra[i], cantidadVenta);
        int ganancia = -1;
        if (costo <= P) {
            ganancia = cantidadVenta * precioVenta - costo;
        }
        if (ganancia > mejor) {
            mejor = ganancia;
            fabricante = i + 1;
        }
    }
    return mejor;
}
