#include <bits/stdc++.h>

using namespace std;

typedef array<array<int, 4>, 4> Node;

const int MOD=1e9+7;

const Node NEUTR = [](){
    Node u;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            u[i][i] = i == j;
        }
    }
    return u;
}();


void add(int &v, const int &x){
    v += x;
    if (v >= MOD) {
        v -= MOD;
    }
}

inline int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

Node op(Node &a, Node &b) {
    Node c;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}

const int MAXN = 1e6;

Node st[2 * MAXN];
int n;

Node query(int l, int r){
    Node resl = NEUTR, resr = NEUTR;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) resl = op(resl, st[l++]);
        if (r & 1) resr = op(st[--r], resr);
    }
    return op(resl, resr);
}

const vector<Node> T = [](){
    vector<Node> v;
    for (int m = 0; m < 4; m++) {
        Node u;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                u[i][j] = 0;
            }
        }
        u[m][3] = 1;
        if (m == 0) {
            u[1][2] = 1;
            u[2][1] = 1;
            u[3][3] = 1;
        }
        u[3][m] = 1;
        v.push_back(u);
    }
    return v;
}();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> n >> q;
    vector<int> g(n, 0);
    for (int i = 0; i < n; i++) {
        st[i + n] = T[0];
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = op(st[2 * i], st[2 * i + 1]);
    }
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            b--;
            g[b] ^= a;
            int p = b + n;
            st[p] = T[g[b]];
            while (p /= 2) st[p] = op(st[2 * p], st[2 * p + 1]);
        } else {
            cout << query(a - 1, b)[3][3] << '\n';
        }
    }
    
    return 0;
}