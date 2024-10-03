#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 1 << 17;
 
struct Node {
    int mini = 0, maxi = 0;
};
 
Node st[2 * SZ];
int lazy[2 * SZ];
 
inline Node op(const Node &a, const Node &b) {
    return {min(a.mini, b.mini), max(a.maxi, b.maxi)};
}
 
void pass(int u) {
    if (u < SZ) {
        lazy[2 * u] += lazy[u];
        lazy[2 * u + 1] += lazy[u];
    }
    st[u].mini += lazy[u];
    st[u].maxi += lazy[u];
    lazy[u] = 0;
}
 
void update(int s, int e, int v, int l = 0, int r = SZ, int u = 1) {
    pass(u);
    if (e <= l || r <= s) return;
    if (s <= l && r <= e) {
        lazy[u] = v;
        return pass(u);
    }
    int m = (l + r) / 2;
    update(s, e, v, l, m, 2 * u);
    update(s, e, v, m, r, 2 * u + 1);
    st[u] = op(st[2 * u], st[2 * u + 1]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int p, x;
        cin >> p >> x;
        update(0, p, -2 * x + 3);
        if (st[1].maxi <= 0) {
            cout << "<\n";
        } else if (st[1].mini >= 0) {
            cout << ">\n";
        } else {
            cout << "?\n";
        }
    }
    
    return 0;
}