#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MAX_N = 3000;
 
struct Line {
    ll m, b;
    int k;
    ll operator()(ll x) {
        return m * x + b;
    }
    ld intersectX(Line &o) {
        return ld(b - o.b) / (o.m - m);
    }
};
 
struct LineContainer : deque<Line> {
    void add(ll m, ll b, int k) {
        Line l = Line{m, b, k};
        while (size() >= 2 && l.intersectX(begin()[0]) <= l.intersectX(begin()[1])) {
            pop_front();
        }
        push_front(l);
    }
    pair<ll, int> query(ll x) {
        while (size() >= 2 && end()[-1](x) >= end()[-2](x)) {
            pop_back();
        }
        return {end()[-1](x), end()[-1].k};
    }
};
 
ll h[MAX_N];
int n;
 
pair<ll, int> check(ll lambda) {
    LineContainer dp;
    dp.add(0, 0, 0);
    ll res = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        tie(res, cnt) = dp.query(h[i]);
        res += h[i] * h[i] + lambda;
        cnt++;
        dp.add(-2 * h[i], res + h[i] * h[i], cnt);
    }
    return {res, cnt};
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k;
    cin >> n >> k;
    
    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        h[i] += h[i - 1];
    }
    
    ll l = 0, r = 1e18;
    ll ans = 0;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        auto [res, cnt] = check(m);
        if (cnt >= k) {
            l = m;
            ans = res - k * m;
        } else {
            r = m;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}