#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using vi = vector<int>;

const int INF = 1e9;

struct Resultado {
    ll suma, producto, maximo, minimo;
};

void procesaMatriz(vector<vi> matriz, vector<ll> &resultadoEnArreglo, Resultado &resultadoEnRegistro) {
    resultadoEnRegistro.suma = 0LL;
    resultadoEnRegistro.producto = 1LL;
    resultadoEnRegistro.maximo = -INF;
    resultadoEnRegistro.minimo = INF;
    for (vi &v : matriz) {
        resultadoEnRegistro.suma += accumulate(all(v), 0LL);
        resultadoEnRegistro.producto *= accumulate(all(v), 1LL, multiplies<ll>());
        resultadoEnRegistro.maximo = max(resultadoEnRegistro.maximo, (ll) *max_element(all(v)));
        resultadoEnRegistro.minimo = min(resultadoEnRegistro.minimo, (ll) *min_element(all(v)));
    }
    resultadoEnArreglo = {resultadoEnRegistro.suma, resultadoEnRegistro.producto, resultadoEnRegistro.maximo, resultadoEnRegistro.minimo};
}
