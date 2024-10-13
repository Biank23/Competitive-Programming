#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<int> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m) {
    vector<int> millasMinimas(N - 1, INF), precioMinimo(N - 1, INF);
    for (int i = 0; i < int(a.size()); i++) {
        if (a[i] + 1 != b[i]) continue;
        int j = a[i] - 1;
        if (m[i] != -1) {
            millasMinimas[j] = min(millasMinimas[j], m[i]);
        }
        precioMinimo[j] = min(precioMinimo[j], d[i]);
    }
    int precio = 0, millas = 0;
    for (int i = 0; i < N - 1; i++) {
        if (millasMinimas[i] == INF) precio += precioMinimo[i];
        else millas += millasMinimas[i];
    }
    return {precio, millas};
}