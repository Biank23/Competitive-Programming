#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
 
using ll = long long;
using ld = long double;
 
struct Point {
    ll x, y;
    Point operator-(const Point &o) {
        return {x - o.x, y - o.y};
    }
    ll operator^(const Point &o) {
        return x * o.y - y * o.x;
    }
    bool operator<(const Point &o) {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
    friend ostream& operator<<(ostream& out, const Point &p) {
        return out << "(" << p.x << ", " << p.y << ")";
    }
    friend istream &operator>>(istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
};
 
ll cross(Point a, Point b, Point c) {
    return (b - a) ^ (c - a);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k;
    cin >> k;
    vector<Point> v;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        ++n;
        for (int j = 0; j < n; j++) {
            Point p;
            cin >> p;
            if (p.x < 0) p.x *= -1;
            v.push_back(p);
        }
    }
    
    sort(all(v));
    vector<Point> hull;
    for (Point &p : v) {
        while (sz(hull) > 1 && cross(end(hull)[-2], end(hull)[-1], p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }
    
    Point axisY = {0, 1};
    Point axisX = {1, 0};
    ld ans = 0.0;
    for (int i = 0; i < sz(hull) - 1; i++) {
        Point p = hull[i], d = hull[i + 1] - hull[i];
        ll num = p ^ d;
        ll denY = axisY ^ d;
        ll denX = axisX ^ d;
        ans = max(ans, (ld) num / denY * num / denX);
    }    
    cout << fixed << setprecision(18) << ans << '\n';
    
    return 0;
}