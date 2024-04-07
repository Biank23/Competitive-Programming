#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const int MAX_N = 3e5 + 20;

int ft[MAX_N];

inline int lsb(int i) {
    return i & (-i);
}
 
void update(int i, int v) {
    for (++i; i < MAX_N; i += lsb(i)) {
        ft[i] += v;
    }
}
 
int query(int i) {
    int s = 0;
    for (; i > 0; i -= lsb(i)) {
        s += ft[i];
    }
    return s;
}
 
int query(int l, int r) {
    return query(r) - query(l);
}

ll plantas(vector<int> &h) {
    int n = sz(h);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        update(i, 1);
    }
    sort(all(p), [&](const int &a, const int &b) {
        return h[a] < h[b];
    });
    ll intercambios = 0;
    for (int i : p) {
        intercambios += min(query(0, i), query(i + 1, n));
        update(i, -1);
    }
    return intercambios;
}
