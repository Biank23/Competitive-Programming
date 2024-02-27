#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 1<<18;
 
using ll = long long;
 
ll st[2 * SZ];
pair<ll, bool> lazy[2 * SZ];
#define fst first
#define snd second
 
void pass(int u, int l, int r) {
    if (lazy[u].snd) { //set
        if (u < SZ) {
            lazy[2 * u] = lazy[u];
            lazy[2 * u + 1] = lazy[u];
        }
        st[u] = lazy[u].fst * (r - l);
    } else { //increase
        if (u < SZ) {
            lazy[2 * u].fst += lazy[u].fst;
            lazy[2 * u + 1].fst += lazy[u].fst;
        }
        st[u] += lazy[u].fst * (r - l);
    }
    lazy[u] = {0LL, false};
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
 
void update(int s, int e, pair<ll, bool> v, int l = 0, int r = SZ, int u = 1) {
    pass(u, l, r);
    if (e <= l || r <= s) {
        return;
    }
    if (s <= l && r <= e) {
        lazy[u] = v;
        return pass(u, l, r);
    }
    int m = (l + r) / 2;
    update(s, e, v, l, m, 2 * u);
    update(s, e, v, m, r, 2 * u + 1);
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
        --t, --a;
        if (t == 2) {
            cout << query(a, b) << '\n';
        } else {
            int x;
            cin >> x;
            update(a, b, {x, t});
        }
    }
    
    return 0;
}