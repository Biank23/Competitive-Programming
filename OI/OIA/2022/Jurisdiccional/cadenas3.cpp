#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

vector<int> cadenas(vector<int> &a) {
    const int MAX_A = 2e7 + 9;
    vector<int> p(MAX_A, 1);
    for (int i = 4, j = 2; i < MAX_A; i += 2, j++) {
        p[i] = j;
    }
    for (int i = 3; i * i < MAX_A; i += 2) {
        if (p[i] != 1) continue;
        for (int j = i * i, k = i; j < MAX_A; j += 2 * i, k += 2) {
            if (p[j] == 1) p[j] = k;
        }
    }
    int n = sz(a);
    vector<int> suma(n, 1);
    for (int i = 0; i < n; i++) {
        while (a[i] != 1) {
            suma[i] += a[i];
            a[i] = p[a[i]];
        }
    }
    return suma;
}
