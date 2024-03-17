#include <bits/stdc++.h>

using namespace std;

vector<int> c;

void initialize(int n) {
    c.assign(n, 0);
}

int hasEdge(int u, int v) {
    if (v < u) swap(u, v);
    c[v]++;
    return c[v] == v;
}
