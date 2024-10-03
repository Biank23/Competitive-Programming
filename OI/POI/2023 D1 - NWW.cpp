#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int M;

struct mint {
    int v;
    mint(int x = 0) : v(x) {}
    friend mint &operator*=(mint &a, mint b) {
        a.v = int(1LL * a.v * b.v % M);
        return a;
    }
    friend mint operator*(mint a, mint b) { return a *= b; }
    friend mint &operator+=(mint &a, mint b) {
        if ((a.v += b.v) >= M) a.v -= M;
        return a;
    }
    friend mint operator+(mint a, mint b) { return a += b; }
};

struct STree {
    struct Val {
        mint mult, add;
        Val() : mult(1), add(0) {}
        Val &operator+=(Val o) {
            add += mult * o.add;
            mult *= o.mult;
            return *this;
        }
    };
    struct Node {
        mint val, sum;
        Node() : val(0), sum(0) {}
        friend Node operator+(Node lhs, Node rhs) {
            Node x;
            x.val = lhs.val + rhs.val;
            x.sum = lhs.sum + rhs.sum;
            return x;
        }
    };
    int n;
    vector<Node> st;
    vector<Val> lazy;
    STree(int _n){
        n = 1;
        while (n < _n) n *= 2;
        st.assign(2 * n, Node());
        for (int i = 0; i < _n; i++) st[n + i].val = 1;
        lazy.assign(2 * n, Val());
        for (int i = n - 1; i > 0; i--) {
            st[i] = st[2 * i] + st[2 * i + 1];
        }
    }
    void pass(int u) {
        if (u < n) {
            lazy[2*u] += lazy[u];
            lazy[2*u+1] += lazy[u];
        }
        st[u].sum += st[u].val * lazy[u].add;
        st[u].val *= lazy[u].mult;
        lazy[u] = Val();
    }
    void update(int s, int e, Val v, int l, int r, int u) {
        pass(u);
        if (e <= l || r <= s) return;
        if (s <= l && r <= e) {
            lazy[u] = v;
            return pass(u);
        }
        int m = (l + r) / 2;
        update(s, e, v, l, m, 2 * u);
        update(s, e, v, m, r, 2 * u + 1);
        st[u] = st[2 * u] + st[2 * u + 1];
    }
    void update(int s, int e, mint m){
        Val v;
        if (m.v == -1) v.add = 1;
        else v.mult = m;
        update(s, e, v, 0, n, 1);
    }
    Node query(int s, int e, int l, int r, int u) {
        pass(u);
        if (e <= l || r <= s) return Node();
        if (s <= l && r <= e) return st[u];
        int m = (l + r) / 2;
        return query(s, e, l, m, 2 * u) + query(s, e, m, r, 2 * u + 1);
    }
    Node query(int s, int e) { return query(s, e, 0, n, 1); }
};

const int MAX_A = 1e6 + 9;
int d[MAX_A];

void sieve() {
    for (int i = 2; i * i < MAX_A; i++) {
        if (d[i]) continue;
        for (int j = i * i; j < MAX_A; j += i) {
            if (!d[j]) d[j] = i;
        }
    }
    for (int i = 1; i < MAX_A; i++) {
        if (!d[i]) d[i] = i;
    }
}

vii factorize(int n) {
    vii f;
    while (n > 1) { 
        int p = d[n], c = 0;
        while (n % p == 0) n /= p, c++;
        f.emplace_back(p, c);
    }
    return f;
}

mint binpow(mint a, int k) {
    mint r = 1;
    while (k > 0) {
        if (k & 1) r *= a;
        a *= a, k /= 2;
    }
    return r;
}

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    sieve();
    int n, q;
    cin >> n >> q >> M;
    vi a(n);
    for (int &x : a) cin >> x;
    vector<vii> queries(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries[r].emplace_back(l, i);
    }
    vi ans(q);
    map<int, vii> m;
    STree st(n);
    for (int i = 0; i < n; i++) {
        for (auto [p, k] : factorize(a[i])) {
            if (m[p].empty()) m[p].emplace_back(INF, -1);
            m[p].emplace_back();
            int r = i + 1, e = 0;
            do {
                m[p].pop_back();
                int l = m[p].back().second + 1;
                st.update(l, r, binpow(p, k - e));
                e = m[p].back().first, r = l;
            } while (m[p].back().first <= k);
            m[p].emplace_back(k, i);
        }
        st.update(0, i + 1, -1);
        for (auto [l, id] : queries[i]) {
            ans[id] = st.query(l, i + 1).sum.v;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}