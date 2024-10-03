#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x),end(x)
 
using ii = pair<int, int>;
 
const int MAX_N = 5e5;
const int INF = 2e9 + 20;
 
ii st[2 * MAX_N];
int sz;
 
const ii NEUTR = {INF, -INF};
 
inline ii op(ii lhs, ii rhs) {
    return {min(lhs.first, rhs.first), max(lhs.second, rhs.second)};
}
 
void init() {
    for (int i = 0; i < 2 * sz; i++) st[i] = NEUTR;
}
 
void update(int p, ii v) {
    p += sz;
    st[p] = op(st[p], v);
    while (p /= 2) st[p] = op(st[2 * p], st[2 * p + 1]);
}
 
ii query(int l, int r) {
    ii res = NEUTR;
    for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
        if (l & 1) res = op(res, st[l++]);
        if (r & 1) res = op(st[--r], res);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), e(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> e[i];
    }
    vector<int> vals = x;
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    sz = sz(vals);
    const auto pos = [&](int v) {
        return int(lower_bound(all(vals), v) - begin(vals));
    };
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](const int &lhs, const int &rhs) {
        if (e[lhs] != e[rhs]) return e[lhs] > e[rhs];
        return x[lhs] < x[rhs];
    });
    init();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p = pos(x[id[i]]);
        int mini = query(p, sz).first;
        int maxi = query(0, p + 1).second;
        int diff = x[id[i]] - e[id[i]];
        int sum = x[id[i]] + e[id[i]];
        if (mini > diff && maxi < sum) ans++;
        update(p, ii{diff, sum});
    }
    cout << ans << '\n';
    
    return 0;
}