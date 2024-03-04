#include <bits/stdc++.h>
 
using namespace std;

using ll = long long;
const int SZ = 1<<19;

ll st[2 * SZ], lazy[2 * SZ];

void pass(int u) {
    if (u < SZ) {
        lazy[2 * u] += lazy[u];
        lazy[2 * u + 1] += lazy[u];
    }
    st[u] += lazy[u];
    lazy[u] = 0;
}

void update(int s, int e, ll v, int l = 0, int r = SZ, int u = 1) {
    pass(u);
    if (e <= l || r <= s) {
        return;
    } 
    if (s <= l && r <= e) {
        lazy[u] = v;
        return pass(u); 
    }
    int m = (l + r) / 2;
    update(s, e, v, l, m, 2 * u);
    update(s, e, v, m, r, 2 * u + 1);
    st[u] = max(st[2 * u], st[2 * u + 1]);
}
 
using ii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<ii>> intervals(n);
    for (int i = 0; i < m; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        --l, --r;
        intervals[r].emplace_back(l, a);
    }

    for (int r = 0; r < n; r++) {
        update(r, r + 1, st[1]);
        for (auto [l, a] : intervals[r]) {
            update(l, r + 1, a);
        }
    }
    cout << st[1] << '\n';

    return 0;
}
