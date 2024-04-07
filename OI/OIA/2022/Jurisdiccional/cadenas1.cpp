#include <bits/stdc++.h>

using namespace std;

int cadenas(int a) {
    int suma = 1;
    for (int i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            suma += a;
            a /= i;
        }
    }
    if (a != 1) suma += a;
    return suma;
}
