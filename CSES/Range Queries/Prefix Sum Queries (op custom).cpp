#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
struct Node {
    ll sum, prefix;
    Node(ll v = 0) {
        sum = v;
        prefix = max(0LL, v);
    }
    friend Node op(const Node &a, const Node &b) {
        Node c;
        c.sum = a.sum + b.sum;
        c.prefix = max(a.prefix, a.sum + b.prefix);
        return c;
    }
};
 
const int MAX_N = 2e5+9;
 
Node st[2 * MAX_N];
int n;
 
void update(int i, int v) {
    for (st[i += n] = v; i /= 2;) st[i] = op(st[2 * i], st[2 * i + 1]);
}
 
Node query(int l, int r) {
    Node lans, rans;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l&1) lans = op(lans, st[l++]);
        if (r&1) rans = op(st[--r], rans);
    }
    return op(lans, rans);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st[i + n] = v;
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = op(st[2 * i], st[2 * i + 1]);
    }
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        --a;
        
        if (t == 1) {
            update(a, b);
        } else {
            cout << query(a, b).prefix << '\n';
        }
    }
}