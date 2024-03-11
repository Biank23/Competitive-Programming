#include <bits/stdc++.h>
 
using namespace std;
 
struct Node {
    int value;
    Node *left = nullptr, *right = nullptr;
    Node(int v = 0) : value(v) {}
};
 
Node *root = new Node();
 
int query(int s, int e, int l = 0, int r = 1<<30, Node *u = root) {
    if (u == nullptr || e <= l || r <= s) return 0;
    if (s <= l && r <= e) return u->value;
    int m = (l + r) / 2;
    return query(s, e, l, m, u->left) + query(s, e, m, r, u->right);
}
 
int val(Node *u) {
    if (u == nullptr) return 0;
    return u->value;
}
 
Node* update(int p, int v, int l = 0, int r = 1<<30, Node *u = root) {
    if (u == nullptr) u = new Node();
    if (r - l == 1) {
        u->value += v;
        return u;
    }
    int m = (l + r) / 2;
    if (p < m) {
        u->left = update(p, v, l, m, u->left);
    } else {
        u->right = update(p, v, m, r, u->right);
    }
    u->value = val(u->left) + val(u->right);
    return u;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        update(p[i], 1);
    }
    
    for (int i = 0; i < q; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        if (t == '!') {
            --a;
            update(p[a], -1);
            p[a] = b;
            update(p[a], 1);
        } else {
            cout << query(a, b + 1) << '\n';
        }
    }
    
    return 0;
}