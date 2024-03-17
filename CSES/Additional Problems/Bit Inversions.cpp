#include <bits/stdc++.h>
 
using namespace std;
 
struct Node {
    int prefix[2], suffix[2], ans[2], sz;
    Node() : prefix(), suffix(), ans(), sz() {}
    Node(bool b) : Node() {
        prefix[b] = suffix[b] = ans[b] = sz = 1;
    }
    friend Node op(const Node &a, const Node &b) {
        Node c;
        for (int i : {0, 1}) {
            c.prefix[i] = a.prefix[i] + (a.prefix[i] == a.sz) * b.prefix[i];
            c.suffix[i] = b.suffix[i] + (b.suffix[i] == b.sz) * a.suffix[i];
            c.ans[i] = max({a.ans[i], b.ans[i], a.suffix[i] + b.prefix[i]});
        }
        c.sz = a.sz + b.sz;
        return c;
    }
};
 
const int SZ = 1<<18;
 
Node st[2 * SZ];
 
void init(string &s) {
    for (int i = 0; i < ssize(s); i++) {
        bool bit = s[i] == '1';
        st[i + SZ] = bit;
    }
    for (int i = SZ - 1; i > 0; i--) {
        st[i] = op(st[2 * i], st[2 * i + 1]);
    }
}
 
 
void update(int p, bool bit) {
    p += SZ;
    st[p] = bit;
    while (p /= 2) {
        st[p] = op(st[2 * p], st[2 * p + 1]);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    int q;
    cin >> s >> q;
    init(s);
    
    while (q--) {
        int p;
        cin >> p;
        --p;
        s[p] = '0' + '1' - s[p];
        update(p, s[p] == '1');
        cout << max(st[1].ans[0], st[1].ans[1]) << ' ';
    }
    
    return 0;
}