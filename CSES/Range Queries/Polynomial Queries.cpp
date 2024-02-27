#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 1<<18;
 
using ll = long long;
using pll = pair<ll, ll>;
 
ll st[2 * SZ];
pll lazy[2 * SZ];
#define fst first
#define snd second
 
pll& operator+=(pll &x, pll o) {
    x.fst += o.fst;
    x.snd += o.snd;
    return x;
}
 
void pass(int u, int l, int r) {
    if (u < SZ) {
        lazy[2 * u] += lazy[u];
        lazy[2 * u + 1] += lazy[u];
        int m = (l + r) / 2;
        lazy[2 * u + 1].fst += (m - l) * lazy[u].snd;
    }
    st[u] += lazy[u].fst*(r-l) + lazy[u].snd*(r-l)*(r-l-1)/2 ;
    lazy[u] = {0LL, 0LL};
}
 
ll query(int s, int e, int l = 0, int r = SZ, int u = 1) {
    pass(u, l, r);
    if (e <= l || r <= s) {
        return 0LL;
    }
    if (s <= l && r <= e) {
        return st[u];
    }
    int m = (l + r) / 2;
    return query(s, e, l, m, 2 * u) +
            query(s, e, m, r, 2 * u + 1);
}
 
void update(int s, int e, int l = 0, int r = SZ, int u = 1) {
    pass(u, l, r);
    if (e <= l || r <= s) {
        return;
    }
    if (s <= l && r <= e) {
        lazy[u] += pll{l - s + 1, 1};
        return pass(u, l, r);
    }
    int m = (l + r) / 2;
    update(s, e, l, m, 2 * u);
    update(s, e, m, r, 2 * u + 1);
    st[u] = st[2 * u] + st[2 * u + 1];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> st[i + SZ];
    }
    for (int i = SZ - 1; i > 0; i--) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
    
    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        --a;
        if (t == 2) {
            cout << query(a, b) << '\n';
        } else {
            update(a, b);
        }
    }
    
    return 0;
}