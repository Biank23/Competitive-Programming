#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

vector<int> cadenas(vector<int> &a) {
    int n = sz(a);
    vector<int> suma(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <= a[i]; j++) {
            while (a[i] % j == 0) {
                suma[i] += a[i];
                a[i] /= j;
            }
        }
        if (a[i] != 1) suma[i] += a[i];
    }
    return suma;
}
