#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;

int filtranum(vi &numeros, vi &resultado) {
    resultado.clear();
    for (int numero : numeros) {
        string s = to_string(numero);
        if (s.front() == s.back()) {
            resultado.push_back(numero);
        }
    }
    return sz(resultado);
}
