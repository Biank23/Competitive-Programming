#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(x.size())

using vi = vector<int>;

const int ADD = 0;
const int ERASE = -1;
const int ASK = 1;

struct Event {
    int type, x, y1, y2;
    Event(int a, int b, int c, int d) : type(a), x(b), y1(c), y2(d) {}
    bool operator<(const Event &o) {
        if (x != o.x) return x < o.x;
        return type < o.type;
    }
};

struct SegTree {
    int n;
    vi st, lazy;
    SegTree(int _n) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
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
    int query_and_update(int s, int e, int v, int l, int r, int u) {
        pass(u);
        if (e <= l || r <= s) {
            return 0LL;
        }
        if (s <= l && r <= e) {
            lazy[u] += v;
            pass(u);
            return st[u];
        }
        int m = (l + r) / 2;
        int left_answer = query_and_update(s, e, v, l, m, 2 * u);
        int right_answer = query_and_update(s, e, v, m, r, 2 * u + 1);
        st[u] = max(st[2 * u], st[2 * u + 1]);
        return max(left_answer, right_answer);
    }
    int query(int s, int e) {
        return query_and_update(s, e, 0, 0, n, 1);
    }
    void update(int s, int e, int v) {
        query_and_update(s, e, v, 0, n, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vi x1(n), x2(n), y1(n), y2(n), vals(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        vals[2 * i] = y1[i], vals[2 * i + 1] = y2[i];
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    auto pos = [&](int val) {
        return int(lower_bound(all(vals), val) - begin(vals));
    };
    vector<Event> e;
    for (int i = 0; i < n; i++) {
        y1[i]=pos(y1[i]), y2[i]=pos(y2[i]);
        e.emplace_back(ADD, x1[i], y1[i], y2[i]);
        e.emplace_back(ERASE, x2[i], y1[i], y2[i]);
        e.emplace_back(ASK, x1[i], y1[i], y2[i]);
    }
    sort(all(e));
    SegTree st(sz(vals));
    bool res = false;
    for (auto [type, x, yl, yr] : e) {
        if (type == ADD) st.update(yl, yr, 1);
        if (type == ERASE) st.update(yl, yr, -1);
        if (type == ASK) res |= st.query(yl, yr) > 1;
    }
    if (res) cout<<"JAH\n";
    else cout<<"EI\n";
    
    return 0;
}
