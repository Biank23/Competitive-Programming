#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 1<<18;
 
using ll = long long;
 
const ll INF = 1e18;
 
ll st[2 * SZ], lazy[2 * SZ];
 
void pass(int u) {
    if (u < SZ) {
        lazy[2 * u] += lazy[u];
        lazy[2 * u + 1] += lazy[u];
    }
    st[u] += lazy[u];
    lazy[u] = 0LL;
}
 
ll query(int s, int e, int l = 0, int r = SZ, int u = 1) {
    pass(u);
    if (e <= l || r <= s) {
        return -INF;
    }
    if (s <= l && r <= e) {
        return st[u];
    }
    int m = (l + r) / 2;
    return max(query(s, e, l, m, 2 * u),
            query(s, e, m, r, 2 * u + 1));
}
 
void update(int s, int e, int v, int l = 0, int r = SZ, int u = 1) {
    pass(u);
    if (e <= l || r <= s) {
        return;
    }
    if (s <= l && r <= e) {
        lazy[u] = v;
        return pass(u);
    }
    int m = (l + r) / 2;
    update(s, e, v, l, m, 2 * u);
    update(s, e, v, m, r, 2 * u + 1);
    st[u] = max(st[2 * u], st[2 * u + 1]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> v(n);
    vector<ll> p(n + 1);
    p[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p[i + 1] = p[i] + v[i];
    }
    ++n;
    for (int i = 0; i < n; i++) {
        st[i + SZ] = p[i];
    }
    for (int i = n; i < SZ; i++) {
        st[i + SZ] = -INF;
    }
    for (int i = SZ - 1; i > 0; i--) {
        st[i] = max(st[2 * i], st[2 * i + 1]);
    }
    
    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        --a;
        if (t == 1) {
            update(a + 1, n, b - v[a]);
            v[a] = b;
        } else {
            cout << query(a, b + 1) - query(a, a + 1) << '\n';
        }
    }
    
    return 0;
}