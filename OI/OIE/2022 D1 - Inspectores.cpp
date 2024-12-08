#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ll = long long;

const ll INF = 1e18;

struct SegTree {
    int n;
    vector<ll> st, lazy;
    SegTree(int _n) {
        n = 1; while (n < _n) n *= 2;
        st.assign(2 * n, 0);
        lazy.assign(2 * n, 0);
    }
    void pass(int u) {
        if (u < n) {
            lazy[2 * u] += lazy[u];
            lazy[2 * u + 1] += lazy[u];
        }
        st[u] += lazy[u];
        lazy[u] = 0;
    }
    ll update_and_query(int s, int e, int x, int l, int r, int u) {
        pass(u);
        if (e <= l || r <= s) return INF;
        if (s <= l && r <= e) {
            lazy[u] = x;
            pass(u);
            return st[u];
        }
        int m = (l + r) / 2;
        ll left_answer = update_and_query(s, e, x, l, m, 2 * u);
        ll right_answer = update_and_query(s, e, x, m, r, 2 * u + 1);
        st[u] = min(st[2 * u], st[2 * u + 1]);
        return min(left_answer, right_answer);
    }
    void update(int s, int e, int x) {
        update_and_query(s, e, x, 0, n, 1);
    }
    ll query(int s, int e) {
        return update_and_query(s, e, 0, 0, n, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<vii> update(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        update[i].emplace_back(0, x);
        update[i + 1].emplace_back(0, -x);
    }
    vector<vector<pair<ii, int>>> query(n);
    int cant = 0;
    for (int i = 1; i <= q; i++) {
        char c; cin >> c;
        if (c == 'C') {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            update[l].emplace_back(i, x);
            update[r].emplace_back(i, -x);
        } else {
            int p; cin >> p; --p;
            if (c == 'I') {
                query[p].emplace_back(ii{i, -1}, -1);
            } else {
                query[p].back().first.second = i + 1;
                query[p].back().second = cant++;
            }
        }
    }
    vector<ll> ans(cant);
    SegTree st(q + 1);
    for (int i = 0; i < n; i++) {
        for (auto [p, x] : update[i]) {
            st.update(p, q + 1, x);
        }
        for (auto [range, idx] : query[i]) {
            auto [l, r] = range;
            ans[idx] = st.query(l, r);
        }
    }
    for (int i = 0; i < cant; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}