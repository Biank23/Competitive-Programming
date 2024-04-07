#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

const int MAX_N = 1e4;

struct FTree {
    int ft[MAX_N];
    FTree() {
        memset(ft, 0, sizeof ft);
    }
    void update(int i) {
        for (++i; i < MAX_N; i += i&-i) {
            ft[i]++;
        }
    }
    int query(int i) { //[0, i)
        int s = 0;
        for (; i > 0; i -= i&-i) {
            s += ft[i];
        }
        return s;
    }
    int query(int l, int r) { //[l, r)
        return query(r) - query(l);
    }
};

struct Pedido {
    int s, e, t, p;
};

int main() {
    freopen("mercachifle.in", "r", stdin);
	freopen("mercachifle.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<int> vals;
    vector<Pedido> v;
    for (int i = 0; i < 2; i++) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            int s, e;
            cin >> s >> e;
            v.push_back({s, e, i, j});
            vals.push_back(s);
            vals.push_back(e);
        }
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    auto compress = [&vals](int &x) {
        x = int(lower_bound(all(vals), x) - begin(vals));
    };
    for (auto &[s, e, t, p] : v) {
        compress(s), compress(e);
    }
    sort(all(v), [](const Pedido &lhs, const Pedido &rhs) {
        return lhs.e < rhs.e;
    });
    int n = sz(v);
    if (n == 0) {
        cout << "0\n";
        return 0;
    }
    vector<int> dp(n, 0), par(n, -1);
    FTree ft[2];
    for (int i = 0; i < n; i++) {
        int t = v[i].t;
        ft[t].update(v[i].s);
        dp[i] = ft[t].query(v[i].e + 1);
        for (int j = 0; j < i; j++) {
            if (v[j].t == t) continue;
            int val = dp[j] + ft[t].query(v[j].e + 1, v[i].e + 1);
            if (val > dp[i]) {
                dp[i] = val, par[i] = j;
            }
        }
    }
    auto it = max_element(all(dp));
    cout << *it << '\n';
    vector<int> used[2];
    for (int i = int(it - begin(dp)); i >= 0; i = par[i]) {
        int minS = par[i] == -1 ? 0 : v[par[i]].e + 1;
        for (int j = 0; j <= i; j++) {
            if (v[j].t == v[i].t && v[j].s >= minS) {
                used[v[j].t].push_back(v[j].p);
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < sz(used[i]); j++) {
            if (j > 0) cout << " ";
            cout << used[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
