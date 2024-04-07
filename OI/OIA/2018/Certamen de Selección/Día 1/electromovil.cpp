#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

vi electromovil(int E, vi ubicacion, vi autonomia) {
    vi v;
    int p = ubicacion[0];
    int j = 0;
    for (int i = 0; i < E; i++) {
        if (ubicacion[i] > ubicacion[j] + autonomia[j]) return {};
        if (ubicacion[i] > p) {
            if (j != 0) v.push_back(ubicacion[j]);
            p = ubicacion[j] + autonomia[j];
        }
        if (ubicacion[i] + autonomia[i] > ubicacion[j] + autonomia[j]) {
            j = i;
        }
    }
    v.push_back(ubicacion.back());
    return v;
}
