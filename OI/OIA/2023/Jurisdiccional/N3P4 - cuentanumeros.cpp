#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 9;

int ft[MAX_N];

void inicializar() {}

void nuevoNumero(int x) {
    while (x < MAX_N) {
        ft[x]++;
        x += x & -x;
    }
}

int query(int x) {
    int s = 0;
    while (x > 0) {
        s += ft[x];
        x -= x & -x;
    }
    return s;
}

int contar(int a, int b) {
    return query(b) - query(a - 1); 
}
