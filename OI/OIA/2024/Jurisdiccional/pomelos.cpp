#include <bits/stdc++.h>

using namespace std;

struct Nodo {
    long long suma, maximoPrefijo;
    Nodo(int A = 0, int B = 0) {
        suma = A, maximoPrefijo = A + B;
    }
    friend Nodo operator+(Nodo x, Nodo y) {
        Nodo z;
        z.suma = x.suma + y.suma;
        z.maximoPrefijo = max(x.maximoPrefijo, x.suma + y.maximoPrefijo);
        return z;
    }
};

const int T = 1 << 18;

Nodo st[2 * T];

void actualizar(int i, int a, int b) {
    st[i += T] = {a, b};
    while (i /= 2) st[i] = st[2 * i] + st[2 * i + 1];
}

Nodo consulta(int ini, int fin, int izq = 0, int der = T, int u = 1) {
    if (ini <= izq && der <= fin) return st[u];
    if (fin <= izq || der <= ini) return Nodo();
    int med = (izq + der) / 2;
    return consulta(ini, fin, izq, med, 2 * u) + consulta(ini, fin, med, der, 2 * u + 1);
}

vector<long long> pomelos(int N, vector<string> &e, vector<int> &p1, vector<int> &p2) {
    vector<int> A(N, 0), B(N, 0);
    vector<long long> respuesta;
    for (int i = 0; i < int(e.size()); i++) {
        p1[i]--;
        if (e[i] == "C") respuesta.push_back(consulta(p1[i], p2[i]).maximoPrefijo);
        else {
            int j = p1[i];
            if (e[i] == "A") A[j] = p2[i];
            else B[j] = p2[i];
            actualizar(j, A[j], B[j]);
        }
    }
    return respuesta;
}