#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const ll INF = 1e18;
 
struct Line {
    ll m, b;
    Line(ll x = 0, ll y = INF) : m(x), b(y) {}
    ll operator()(int x) {
        return m * x + b;
    }
};
 
const int C = 1<<20;
 
Line st[2 * C];
 
void update(Line f, int u = 1, int l = 0, int r = C) {
    if (r - l == 1) {
        if (f(l) < st[u](l)) st[u] = f;
        return;
    }
    int m = (l + r) / 2;
    if (st[u].m < f.m) swap(st[u], f);
    if (f(m) < st[u](m)) {
        swap(st[u], f);
        update(f, 2 * u, l, m);
    } else {
        update(f, 2 * u + 1, m, r);
    }
}
 
ll query(int x, int u = 1, int l = 0, int r = C) {
    if (r - l == 1) {
        return st[u](x);
    }
    int m = (l + r) / 2;
    if (x < m) {
        return min(st[u](x), query(x, 2 * u, l, m));
    } else {
        return min(st[u](x), query(x, 2 * u + 1, m, r));
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m0;
    cin >> n >> m0;
    
    vector<int> x(n), m(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    
    update(Line{m0, 0});
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = query(x[i]);
        update(Line{m[i], res});
    }
    cout << res << '\n';
    
    return 0;
}