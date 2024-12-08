#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
struct Query {
    int a, b, c, idx;
};
 
struct FTree {
    int n;
    vector<int> ft;
    FTree(int _n) : n(_n + 5), ft(n, 0) {}
    void update(int p) {
        for (++p; p < n; p += p & -p) ft[p]++;
    }
    int query(int p) {
        int s = 0;
        for (++p; p > 0; p -= p & -p) s += ft[p];
        return s;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
 
int compress(const vector<int> &v, int x) {
    return int(lower_bound(all(v), x) - begin(v));
}
 
vector<int> compress(const vector<int> &x, vector<int> &v) {
    sort(all(v)); v.erase(unique(all(v)), end(v));
    vector<int> c(sz(x));
    for (int i = 0; i < sz(x); i++) {
        c[i] = compress(v, x[i]);
    }
    return c;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    
    vector<int> v_s = s, v_t = t;
    vector<Query> v[2];
    for (int i = 0; i < q; i++) {
        Query x; cin >> x.a >> x.b >> x.c; x.idx = i;
        v_s.push_back(x.a); v_t.push_back(x.b);
        v[x.a + x.b < x.c].push_back(x);
    }
    
    vector<int> s_comp = compress(s, v_s), t_comp = compress(t, v_t);
    const int M = max(sz(v_s), sz(v_t));
    
    vector<int> res(q);
    sort(all(v[0]), [](const Query &lhs, const Query &rhs) {
        return lhs.a > rhs.a;
    });
    vector<int> p(n); iota(all(p), 0);
    sort(all(p), [&](const int &lhs, const int &rhs) {
        return s[lhs] > s[rhs];
    });
    FTree ft(M);
    int i = 0;
    for (Query x : v[0]) {
        while (i < n && s[p[i]] >= x.a) {
            ft.update(t_comp[p[i]]);
            i++;
        }
        res[x.idx] = ft.query(compress(v_t, x.b), M);
    }
    
    FTree ftA(M), ftB(M);
    sort(all(v[1]), [](const Query &lhs, const Query &rhs) {
        return lhs.c > rhs.c;
    });
    sort(all(p), [&](const int &lhs, const int &rhs) {
        return s[lhs] + t[lhs] > s[rhs] + t[rhs];
    });
    i = 0;
    for (Query x : v[1]) {
        while (i < n && s[p[i]] + t[p[i]] >= x.c) {
            ftA.update(s_comp[p[i]]);
            ftB.update(t_comp[p[i]]);
            i++;
        }
        res[x.idx] = ftA.query(compress(v_s, x.a), M) + ftB.query(compress(v_t, x.b), M) - i;
    }
    
    for (int i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }
    
    return 0;
}