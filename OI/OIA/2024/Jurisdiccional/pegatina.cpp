#include <bits/stdc++.h>

using namespace std;

string pegatina(int N, int K) {
    string respuesta = "";
    for (int multiplo = K; multiplo <= N; multiplo += K) {
        respuesta += to_string(multiplo);
    }
    return respuesta;
}