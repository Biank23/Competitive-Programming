#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;

struct Node {
    ll x, y;
    int dir;
    Node() : x(), y(), dir() {};
    Node(int t, int M) : Node() {
        if (t == 1) x = M;
        else dir = M;
    }
};

Node op(const Node &a, const Node &b) {
    Node c = a;
    if (a.dir == 0) {
        c.x += b.x;
        c.y += b.y;
    } else if (a.dir == 1) {
        c.x -= b.y;
        c.y += b.x;
    } else if (a.dir == 2) {
        c.x -= b.x;
        c.y -= b.y;
    } else if (a.dir == 3) {
        c.x += b.y;
        c.y -= b.x;
    } else {
        assert(false);
    }
    c.dir += b.dir;
    if (c.dir >= 4) c.dir -= 4;
    return c;
}
 
const int MAX_N = 2e5;

Node st[2 * MAX_N];
int n;

void init() {
    for (int i = 0; i < n; i++) {
        int t, M;
        cin >> t >> M;
        st[i + n] = Node(t, M);
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = op(st[2 * i], st[2 * i + 1]);
    }
}

void update(int i, int t, int M) {
    for (st[i += n] = Node(t, M); i /= 2;) {
         st[i] = op(st[2 * i], st[2 * i + 1]);
    }
}

Node query(int l, int r) {
    Node ansL, ansR;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) ansL = op(ansL, st[l++]);
        if (r & 1) ansR = op(st[--r], ansR);
    }
    return op(ansL, ansR);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    init();
    
    int q;
    cin >> q;
    while (q--) {
        int tq;
        cin >> tq;
        if (tq == 1) {
            int l, r;
            cin >> l >> r;
            Node res = query(l, r + 1);
            cout << res.x << ' ' << res.y << ' ' << res.dir << '\n';
        } else {
            int i, t, M;
            cin >> i >> t >> M;
            update(i, t, M);
        }
    }
    
    return 0;
}