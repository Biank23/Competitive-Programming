#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int INF = 1e9;

vector<int> erupcion(vector<int> &r) {
    int n = sz(r);
    vector<bool> destruido(n, false);
    vector<int> res(n);
    for (int t = 0; t < n; t++) {
        int minimo = INF, indice = -1;
        for (int i = 0; i < n; i++) {
            if (destruido[i]) continue;
            if (minimo > r[i]) {
                minimo = r[i];
                indice = i;
            }
        }
        destruido[indice] = true;
        int regiones = 0;
        for (int i = 0; i < n; i++) {
            if (!destruido[i] && (i == 0 || destruido[i - 1])) regiones++;
        }
        res[t] = regiones;
    }
    return res;
}
