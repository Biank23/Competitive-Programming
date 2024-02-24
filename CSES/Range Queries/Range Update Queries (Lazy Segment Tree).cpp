#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 1<<18;
 
ll st[2*MAX_N], lazy[2*MAX_N];
 
void pass(int u, int l, int r) {
    int sz = r - l;
    if (sz > 1) {
        lazy[2 * u] += lazy[u];
        lazy[2 * u + 1] += lazy[u];
    }
    st[u] += 1LL * sz * lazy[u];
    lazy[u] = 0;
}
 
void update(int s, int e, int val, int l = 0, int r = MAX_N, int u = 1) {
    if (e <= l || r <= s) {
        return;
    }
    
    if (s <= l && r <= e) {
        lazy[u] += val;
        return pass(u, l, r);
    }
    
    int m = (l + r) / 2;
    update(s, e, val, l, m, 2 * u);
    update(s, e, val, m, r, 2 * u + 1);
    st[u] = st[2 * u] + st[2 * u + 1];
}
 
ll query(int pos, int l = 0, int r = MAX_N, int u = 1) {
    pass(u, l, r);
    if (r - l == 1) return st[u];
    int m = (l + r) / 2;
    if (pos < m) {
        return query(pos, l, m, 2 * u);
    } else {
        return query(pos, m, r, 2 * u + 1);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        update(i, i + 1, x);
    }
    
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(a - 1, b, u);
        } else {
            int k;
            cin >> k;
            cout << query(k - 1) << '\n';
        }
    }
    
    return 0;
}