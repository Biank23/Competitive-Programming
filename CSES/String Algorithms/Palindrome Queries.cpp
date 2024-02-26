#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 9;
const int B = 9973;
 
void add(int &x, int v) {
    x += v;
    if (x >= MOD) x -= MOD;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += MOD;
    return s;
}
int mul(int a, int b) {
    return 1LL * a * b % MOD;
}
 
struct STree {
    int n;
    vector<int> st;
    STree(int s) : n(s), st(2 * n) {}
    void update(int i, int v) {
        i += n;
        st[i] = v;
        while (i /= 2) {
            st[i] = st[2 * i];
            add(st[i], st[2 * i + 1]);
        }
    }
    int query(int l, int r) {
        int s = 0;
        l += n, r += n;
        while (l <= r) {
            if (l % 2 == 1) add(s, st[l++]);
            if (r % 2 == 0) add(s, st[r--]);
            l /= 2, r /= 2;
        }
        return s;
    }
};
 
int bpow[MAXN];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    bpow[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        bpow[i] = mul(bpow[i - 1], B);
    }
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    
    STree pref(n), suff(n);
    for (int i = 0; i < n; i++) {
        int val = s[i] - 'a' + 1;
        pref.update(i, mul(val, bpow[n - 1 - i]));
        suff.update(i, mul(val, bpow[i]));
    }
    
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            --pos;
            int val = c - 'a' + 1;
            pref.update(pos, mul(val, bpow[n - 1 - pos]));
            suff.update(pos, mul(val, bpow[pos]));
            s[pos] = c;
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            if (mul(pref.query(l, r), bpow[l]) ==
                mul(suff.query(l, r), bpow[n - 1 - r])) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
}