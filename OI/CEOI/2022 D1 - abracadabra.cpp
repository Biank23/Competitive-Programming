#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 1 << 18;
 
int st[2 * SZ];
 
void update(int i, int v) {
    for (st[i += SZ] = v; i /= 2;) st[i] = st[2 * i] + st[2 * i + 1];
}
 
pair<int, int> search(int x) {
    int u = 1;
    while (u < SZ) {
        u *= 2;
        if (st[u] <= x) {
            x -= st[u];
            u++;
        }
    }
    return {u - SZ, x};
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n), r(n), pos(n);
    vector<pair<int, int>> query[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = i + 1;
        while (r[i] < n && a[r[i]] < a[i]) {
            r[i] = r[r[i]];
        }
    }
    for (int i = 0; i < n; i = r[i]) {
        update(a[i], r[i] - i);
    }
    for (int idx = 0; idx < q; idx++) {
        int t, i;
        cin >> t >> i;
        t = min(t, n);
        --i;
        query[t].emplace_back(i, idx);
    }
    vector<int> res(q);
    for (int t = 0; t <= n; t++) {
        for (auto [i, idx] : query[t]) {
            auto [val, d] = search(i);
            res[idx] = a[pos[val] + d];
        }
        auto [val, d] = search(n / 2);
        if (d == 0) continue;
        int tot = st[val + SZ];
        update(val, d);
        for (int i = pos[val] + d; i < pos[val] + tot; i = r[i]) {
            update(a[i], min(r[i], pos[val] + tot) - i);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << res[i] + 1 << '\n';
    }
    
    return 0;
}