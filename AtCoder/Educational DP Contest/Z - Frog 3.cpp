#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())

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
    
    int n;
    ll c;
    cin >> n >> c;
    
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    vector<ll> dp(n);
    dp[0] = 0;
    deque<Line> dq{Line{-2 * h[0], h[0] * h[0]}};
    for (int i = 1; i < n; i++) {
        while (sz(dq) >= 2 && end(dq)[-1](h[i]) >= end(dq)[-2](h[i])) {
            dq.pop_back();
        }
        dp[i] = end(dq)[-1](h[i]) + h[i] * h[i] + c;
        Line l = Line{-2 * h[i], dp[i] + h[i] * h[i]};
        while (sz(dq) >= 2 && l.intersectX(dq[0]) <= l.intersectX(dq[1])) {
            dq.pop_front();
        }
        dq.push_front(Line{-2 * h[i], dp[i] + h[i] * h[i]});
    }
    cout << dp[n - 1] << '\n';
    
    return 0;
}
