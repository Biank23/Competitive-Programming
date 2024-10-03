#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ii = pair<ll, int>;
const int MAXN = 1009;

ii ft[MAXN];
ii &operator+=(ii &a, const ii &o) {
    a.first += o.first;
    a.second += o.second;
    return a;
}

void update(int i, ii v){
    for (++i; i < MAXN; i += i & -i) ft[i] += v;
}

ii query(int i){
    ii s = {0LL, 0};
    for (; i > 0; i -= i&-i) s += ft[i];
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<int> a(n), p(n);
    for (int &x : a) cin >> x;
    reverse(all(a));
    for (int i = 0; i < n; i++) {
        update(p[i] = i, ii{a[i], 1});
    }
    sort(all(p),[&](const int &x, const int &y) {
        return a[x] < a[y];
    });
    ll cost = 0;
    for (int i : p) {
        auto [sum, cant] = query(i);
        cost += sum - 1LL * a[i] * cant;
        update(i, ii{-a[i], -1});
    }
    cout << 2LL * cost << '\n';
    
    return 0;
}