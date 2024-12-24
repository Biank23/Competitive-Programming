#include <bits/stdc++.h>

using namespace std;

#define sz(a) int(a.size())

const int INF = 1e9;

long long monedas(vector<int> &a) {
    int n = sz(a);
    const int K = 2 * a[n - 1];
    vector<int> cant(K, INF);
    cant[0] = 0;
    for (int x = 1; x < K; x++) {
        int i = n - 1;
        while (a[i] > x) i--;
        cant[x] = cant[x - a[i]] + 1;
        while (i --> 0) {
            if (cant[x] > cant[x - a[i]] + 1) return x;
        }
    }
    return -1;
}
