#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x),end(x)

using ii = pair<int, int>;

const int INF = 2e9;

struct SparseTable {
    int n;
    vector<vector<int>> st;
    SparseTable(vector<int> &v) {
        n = sz(v);
        int log = 32 - __builtin_clz(n);
        st.assign(log, vector<int>(n, -INF));
        for (int i = 0; i < n; i++) {
            st[0][i] = v[i];
        }
        for (int i = 0; i < log - 1; i++) {
            for (int j = 0; j < n - (1 << i); j++) {
                st[i + 1][j] = max(st[i][j], st[i][j + (1 << i)]);
            }
        }
    }
    int query(int l, int r) {
        if (l == r) return -INF;
        int log = 31 - __builtin_clz(r - l);
        return max(st[log][l], st[log][r - (1 << log)]);
    }
};

struct FenwickTree {
    int n;
    vector<int> ft;
    FenwickTree(int _n) : n(_n + 10), ft(n, 0) {}
    void update(int i, int v) {
        for (i += 3; i < n; i += i & -i) ft[i] += v;
    }
    int query(int i) {
        int s = 0;
        for (i += 3; i > 0; i -= i & -i) s += ft[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 2, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> left(n + 2), right(n + 2);
    for (int i = 1; i <= n; i++) {
        int j = i - 1;
        while (a[j] > a[i]) j = left[j];
        left[i] = j;
    }
    for (int i = n; i >= 1; i--) {
        int j = i + 1;
        while (a[j] >= a[i]) j = right[j];
        right[i] = j;
    }
    int q;
    cin >> q;
    vector<ii> update[n + 3], query[n + 3];
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        query[l].emplace_back(r, i);
    }
    SparseTable st(a);
    for (int i = 1; i <= n; i++) {
        int lo = 0, hi = left[i];
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (st.query(mid, left[i] + 1) <= a[i]) hi = mid;
            else lo = mid;
        }
        int l1 = hi, l2 = left[i];
        int r1 = i, r2 = right[i] - 1;
        update[l1].emplace_back(r1, 1);
        update[l1].emplace_back(r2 + 1, -1);
        update[l2 + 1].emplace_back(r1, -1);
        update[l2 + 1].emplace_back(r2 + 1, 1);
    }
    FenwickTree ft(n);
    vector<int> res(q);
    for (int i = 0; i <= n; i++) {
        for (auto [j, v] : update[i]) {
            ft.update(j, v);
        }
        for (auto [j, idx] : query[i]) {
            res[idx] = ft.query(j);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << res[i] + 1 << ' ';
    }
    
    return 0;
}