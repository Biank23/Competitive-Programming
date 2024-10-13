#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int SZ = 1 << 20;
const int L = 5;

array<int, L> operator+(array<int, L> lhs, array<int, L> rhs) {
    array<int, L> sum;
    for (int i = 0; i < L; i++) sum[i] = lhs[i] + rhs[i];
    return sum;
}

array<int, L> &operator+=(array<int, L> &x, const array<int, L> &v) {
    for (int i = 0; i < L; i++) x[i] = v[x[i]];
    return x;
}

struct Node {
    array<int, L> cnt;
    array<int, L> lazy;
    Node() {
        fill(all(cnt), 0);
        iota(all(lazy), 0);
    }
};

Node st[2 * SZ];

void pass(int u) {
    if (u < SZ) {
        st[2 * u].lazy += st[u].lazy;
        st[2 * u + 1].lazy += st[u].lazy;
    }
    array<int, L> cnt_copy = st[u].cnt;
    fill(all(st[u].cnt), 0);
    for (int i = 0; i < L; i++) {
        st[u].cnt[st[u].lazy[i]] += cnt_copy[i];
    }
    iota(all(st[u].lazy), 0);
}

void update(int s, int e, const array<int, L> &v, int l = 0, int r = SZ, int u = 1) {
    pass(u);
    if (e <= l || r <= s) return;
    if (s <= l && r <= e) {
        st[u].lazy = v;
        return pass(u);
    }
    int m = (l + r) / 2;
    update(s, e, v, l, m, 2 * u);
    update(s, e, v, m, r, 2 * u + 1);
    st[u].cnt = st[2 * u].cnt + st[2 * u + 1].cnt;
}

void travel(int l = 0, int r = SZ, int u = 1) {
    pass(u);
    if (r - l == 1) {
        for (int i = 0; i < L; i++) {
            if (st[u].cnt[i]) cout << char('a' + i);
        }
        return;
    }
    int m = (l + r) / 2;
    travel(l, m, 2 * u);
    travel(m, r, 2 * u + 1);
}

int find(int x, int p) {
    int u = 1;
    pass(u);
    while (u < SZ) {
        u *= 2;
        pass(u);
        if (st[u].cnt[p] < x) {
            x -= st[u].cnt[p];
            u++;
            pass(u);
        }
    }
    return u - SZ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    string s;
    cin >> n >> q >> s;
    
    for (int i = 0; i < n; i++) {
        st[i + SZ].cnt[s[i] - 'a']++;
    }
    for (int i = SZ - 1; i > 0; i--) {
        st[i].cnt = st[2 * i].cnt + st[2 * i + 1].cnt;
    }
    while (q--) {
        int c;
        char a, b;
        cin >> c >> a >> b;
        int p = find(c, a - 'a');
        array<int, L> v;
        iota(all(v), 0);
        v[a - 'a'] = b - 'a';
        update(0, p + 1, v);
    }
    travel();
    cout<<'\n';
    
    return 0;
}