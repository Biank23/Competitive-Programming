#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
struct Line {
    ll m, b;
    ll operator()(ll x){
        return m * x + b;
    }
    friend string to_string(Line l) {
        return to_string(l.m) + "*x + " + to_string(l.b);
    }
    ld intersectX(Line l){
        return ld(b - l.b) / (l.m - m);
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m0;
    cin >> n >> m0;
    
    vector<int> x(n), m(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    
    deque<Line> dq{{m0, 0}};
    ll res = 0;
    for (int i = 0; i < n; i++) {
        while (ssize(dq) > 1 && end(dq)[-1](x[i]) >= end(dq)[-2](x[i])) {
            dq.pop_back();
        }
        res = end(dq)[-1](x[i]);
        Line l = {m[i], res};
        while (ssize(dq) > 1 && l.intersectX(dq[0]) <= l.intersectX(dq[1])) {
            dq.pop_front();
        }
        dq.push_front(l);
    }
    cout << res << '\n';
    
    return 0;
}