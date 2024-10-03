#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;
using ld = long double;

struct Point {
    ld x, y;
    Point operator-(const Point &o){
        return {x - o.x, y - o.y};
    }
    ld abs() {
        return sqrt(x * x + y * y);
    }
    friend istream &operator>>(istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
};

inline ld dist(Point a, Point b) {
    return (a - b).abs();
}

ld solve(vector<Point> p, ld l, vector<bool> m) {
    int n = sz(p);
    p.resize(2 * n + 1), m.resize(2 * n + 1);
    for (int i = n; i <= 2 * n; i++) {
        p[i] = p[i - n];
        m[i] = m[i - n];
    }
    ld tot = 0.0;
    for (int i = 0; i < n; i++) {
        if (m[i]) tot += dist(p[i], p[i + 1]);
    }
    ld sum = 0.0;
    ld h = 0.0;
    int j = 0;
    ld best = tot;
    auto upd = [&](int i, int s) {
        ld d = dist(p[i], p[i + 1]);
        sum += d * s;
        h += m[i] * d * s;
    };
    for (int i = 0; i < 2 * n; i++) {
        while (j < 2 * n && sum <= l) upd(j++, 1);
        if (m[j - 1] && sum > l) best = min(best, tot - h + sum - l);
        else best = min(best, tot - h);
        upd(i, -1);
    }
    return max(best, 0.0l);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    ld l;
    cin >> n >> l >> k;
    vector<bool> m(n, false);
    while (k--) {
        int a; cin >> a;
        m[a - 1] = true;
    }
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << solve(p, l, m) << '\n';
    
    return 0;
}