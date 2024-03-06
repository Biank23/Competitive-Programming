#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
struct Line {
    ll m, b;
    ll operator()(ll x) {
        return m * x + b;
    }
    ld intersectX(Line &o) {
        return ld(b - o.b) / (o.m - m);
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<ll> h(n + 1);
    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        h[i] += h[i - 1];
    }
    
    deque<Line> dq;
    
    auto add = [&](ll m, ll b) {
        Line l = Line{m, b};
        while (ssize(dq) >= 2 && l.intersectX(dq[0]) <= l.intersectX(dq[1])) {
            dq.pop_front();
        }
        dq.push_front(l);
    };
    
    auto query = [&](ll x) {
        while (ssize(dq) >= 2 && end(dq)[-1](x) >= end(dq)[-2](x)) {
            dq.pop_back();
        }
        return end(dq)[-1](x);
    };
    
    vector<ll> dp(n + 1, 0);
    for (int i = 0; i < k; i++) {
        dq.clear();
        add(-2 * h[i], dp[i] + h[i] * h[i]);
        for (int j = i + 1; j <= n; j++) {
            ll newDP = query(h[j]) + h[j] * h[j];
            if (i) add(-2 * h[j], dp[j] + h[j] * h[j]);
            dp[j] = newDP;
        }
    }
    cout << dp[n] << '\n';
    
    return 0;
}