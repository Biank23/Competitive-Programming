#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MAX_N = 3001;
const ll INF = 1e18;
 
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
 
ll pref[MAX_N], acumL[MAX_N], acumR[MAX_N];
ll x[MAX_N];
int n;
 
pair<ll, int> check(ll lambda) {
    LineContainer cht0, cht1;
    cht1.add(0, 0, 0);
    ll dp0 = 0, dp1 = 0;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        tie(dp0, cnt0) = cht1.query(i - n + 1);
        dp0 += acumR[i] - (n - i - 1) * pref[i] + lambda;
        cnt0++;
        cht0.add(-i, dp0 - acumL[i] + i * pref[i], cnt0);
        tie(dp1, cnt1) = cht0.query(pref[i]);
        dp1 += acumL[i];
        cht1.add(-pref[i], dp1 - acumR[i], cnt1);
    }
    return {dp1, cnt1};
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pref[i] = pref[i - 1] + x[i];
        acumL[i] = acumL[i - 1] + x[i] * i; 
        acumR[i] = acumR[i - 1] + x[i] * (n - i - 1);
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