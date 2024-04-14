#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
#define pb push_back

vector<bool> laboratorio(vector<vi> pruebas);

int mote_con_huesito(int n) {
    int pot = 1, log = 0;
    while (pot < n) {
        pot *= 2;
        log++;
    }
    vector<vi> pruebas(log);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < log; j++) {
            if (i >> j & 1) pruebas[j].pb(i + 1);
        }
    }
    vector<bool> v = laboratorio(pruebas);
    int ans = 0;
    for (int i = 0; i < log; i++) {
        if (v[i]) ans += 1 << i;
    }
    return ans + 1;
}
