#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;

const int INF = 1e9 + 20;

bool check(vi &c, vi &p, ll target) {
    ll sum = c[0];
    int count = 1;
    ll prevDiff = c[0] - target;
    for (int i = 0; i < sz(p); i++) {
        sum += c[i+1] - p[i];
        count++;
        ll diff = sum - count * target;
        if (prevDiff >= 0 && diff < c[i + 1] - target) {
            sum = c[i + 1];
            count = 1;
            diff = c[i + 1] - target;
        }
        prevDiff = diff;
    }
    return prevDiff >= 0;
}

int panes(vi &ciudades, vi &peajes) {
    ll l = 0, r = INF;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (check(ciudades, peajes, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return (int) l;
}
