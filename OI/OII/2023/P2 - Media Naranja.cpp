#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define pb push_back

using ll = long long;

struct Range {
    int l, m, r;
};

const int MAX_N = 6e5 + 9;

int ft[MAX_N];

void upd(int i, int v) {
    i++;
    while (i < MAX_N) {
        ft[i] += v;
        i += i&-i;
    }
}

int query(int i) {
    i++;
    int s = 0;
    while (i > 0) {
        s += ft[i];
        i -= i&-i;
    } 
    return s;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<Range> v;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        int m = l + r;
        l *= 2, r *= 2;
        v.pb({l, m, r});
        vals.pb(l), vals.pb(m), vals.pb(r);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    auto comp = [&](int x) {
        return int(lower_bound(all(vals), x) - begin(vals));
    };
    const int S = sz(vals);
    vector<int> add[S], erase[S];
    vector<pair<int, int>> ask[S];
    for (auto &[l, m, r] : v) {
        l = comp(l), m = comp(m), r = comp(r);
        add[l].pb(m), erase[r].pb(m), ask[m].pb({l, r});
    }
    ll ans = 0;
    for (int i = 0; i < S; i++) {
        for (int m : add[i]) upd(m, 1);
        for (auto [l, r] : ask[i]) ans += query(l, r);
        for (int m : erase[i]) upd(m, -1);
    }
    cout << (ans - n) / 2 << '\n';
    
    return 0;
}