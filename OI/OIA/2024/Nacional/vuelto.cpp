#include <bits/stdc++.h>

using namespace std;

int vuelto(int V) {
    int res = 0;
    vector<int> monedas = {100, 50, 25, 10, 5, 2, 1};
    for (int x : monedas) {
        while (V >= x) V -= x, res++;
    }
    return res;
}
