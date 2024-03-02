#include <bits/stdc++.h>
 
using namespace std;
 
struct Node {
    int mini, maxi;
    Node(int v = 0) : mini(v), maxi(v) {}
    Node& operator+=(int x){
        mini += x;
        maxi += x;
        return *this;
    }
};
 
Node op(const Node &a, const Node &b) {
    Node c;
    c.mini = min(a.mini, b.mini);
    c.maxi = max(a.maxi, b.maxi);
    return c;
}
 
const int SZ = 1<<18;
 
Node st[2 * SZ];
int lazy[2 * SZ];
 
void pass(int u) {
    if (u < SZ) {
        lazy[2 * u] += lazy[u];
        lazy[2 * u + 1] += lazy[u];
    }
    st[u] += lazy[u];
    lazy[u] = 0;
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
    st[u] = op(st[2 * u], st[2 * u + 1]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;
        if (s == 1) {
            update(0, c, 1);
        } else {
            update(0, c, -1);
        }
        if (st[1].mini >= 0) {
            cout << ">\n";
        } else if (st[1].maxi <= 0) {
            cout << "<\n";
        } else {
            cout << "?\n";
        }
    }
    
    return 0;
}