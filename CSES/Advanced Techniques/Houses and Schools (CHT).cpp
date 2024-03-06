#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MAX_N = 3001;
const ll INF = 1e18;
 
struct Line {
    ll m, b;
    ll operator()(ll x) {
        return m * x + b;
    }
    ld intersectX(Line &o) {
        return ld(b - o.b) / (o.m - m);
    }
};
 
struct LineContainer : deque<Line> {
    void add(ll m, ll b) {
        Line l = Line{m, b};
        while (size() >= 2 && l.intersectX(begin()[0]) <= l.intersectX(begin()[1])) {
            pop_front();
        }
        push_front(l);
    }
    ll query(ll x) {
        while (size() >= 2 && end()[-1](x) >= end()[-2](x)) {
            pop_back();
        }
        return end()[-1](x);
    }
};
 
ll pref[MAX_N], acumL[MAX_N], acumR[MAX_N];
ll x[MAX_N], dp0[MAX_N][MAX_N], dp1[MAX_N][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pref[i] = pref[i - 1] + x[i];
        acumL[i] = acumL[i - 1] + x[i] * i; 
        acumR[i] = acumR[i - 1] + x[i] * (n - i - 1);
    }
    
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            dp0[i][j] = INF;
            dp1[i][j] = INF;
        }
    }
    
    dp1[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        LineContainer cht0, cht1;
        cht1.add(0, 0);
        for (int j = 1; j <= n; j++) {
            dp0[i][j] = cht1.query(j - n + 1) + acumR[j] - (n - j - 1) * pref[j];
            cht0.add(-j, dp0[i][j] - acumL[j] + j * pref[j]);
            dp1[i][j] = cht0.query(pref[j]) + acumL[j];
            cht1.add(-pref[j], dp1[i - 1][j] - acumR[j]);
        }
    }
    cout << dp1[k][n] << '\n';
    
    return 0;
}