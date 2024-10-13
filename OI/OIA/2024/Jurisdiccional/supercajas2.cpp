#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int K = 51;

using vi = vector<int>;

void ordenar(int &X, int &Y, int &Z) {
    if (X > Y) swap(X, Y);
    if (X > Z) swap(X, Z);
    if (Y > Z) swap(Y, Z);
}

int supercajas(int N, int X, int Y, int Z, vi &a, vi &b, vi &c) {
    vector<vector<vi>> contador(K, vector<vi>(K, vi(K, 0)));
    for (int i = 0; i < int(a.size()); i++) {
        ordenar(a[i], b[i], c[i]);
        contador[a[i]][b[i]][c[i]]++;
    }
    ordenar(X, Y, Z);
    int volumenMinimo = INF;
    for (int A = X; A < K; A++)
    for (int B = Y; B < K; B++) 
    for (int C = Z; C < K; C++) {
        if (contador[A][B][C] >= N) {
            volumenMinimo = min(volumenMinimo, A * B * C);
        }   
    }
    if (volumenMinimo == INF) return -1;
    return volumenMinimo - X * Y * Z;
}