#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;

const int ALPHA = 26;

int vial(int K, int C, string &tipo, vi &cuantos, vi &pos, string &queHay) {
    vector<pair<int, char>> eventos;
    int n = sz(pos);
    for (int i = 0; i < n; i++) {
        eventos.emplace_back(pos[i], queHay[i]);
    }
    sort(all(eventos));
    vi tipoIdx(ALPHA);
    int T = sz(tipo);
    for (int i = 0; i < T; i++) {
        tipoIdx[tipo[i] - 'A'] = i;
    }
    vi pendientes(T, 0);
    int ceros = T;
    int ini = -1;
    int costo = C * 1000000 + n * K;
    for (int i = 0; i < n; i++) {
        auto [p, ch] = eventos[i];
        if (islower(ch)) {
            int idx = tipoIdx[ch - 'a'];
            if (pendientes[idx] > 0) {
                pendientes[idx]--;
                if (pendientes[idx] == 0) ceros++;
                if (ceros == T) {
                    costo += C * 2 * (p - ini);
                    ini = -1;
                }
            } else {
                cuantos[idx]++;
            }
        } else {
            int idx = tipoIdx[ch - 'A'];
            if (i + 1 < n && p == eventos[i + 1].first && ch - 'A' == eventos[i + 1].second - 'a') {
                costo -= 2 * K;
                i++;
            } else if (cuantos[idx] > 0) {
                cuantos[idx]--;
            } else {
                if (ini == -1) ini = p;
                pendientes[idx]++;
                if (pendientes[idx] == 1) ceros--;
            }
        }
    }
    return costo;
}
