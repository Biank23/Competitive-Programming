#include <bits/stdc++.h>

using namespace std;

string sumadigitos(string &s) {
    string respuesta;
    int L = int(s.size());
    for (int i = 0; i < L; i++) {
        if (s[i] == '?') {
            int suma = 0;
            if (i - 1 >= 0) suma += s[i - 1] - '0';
            if (i + 1 < L) suma += s[i + 1] - '0';
            respuesta += char('0' + suma);
        } else respuesta += s[i];
    }
    return respuesta;
}