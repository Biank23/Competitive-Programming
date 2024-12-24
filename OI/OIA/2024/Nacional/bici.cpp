#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int bici(vector<int> &c) {
    int n = sz(c);
    int T = 0;
    for (int i = 0; i < n; i++) T += c[i];
    int cant = T / n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] > cant) res += c[i] - cant;
    }
    return res;
}
