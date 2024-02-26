#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
 
using ll = long long;
 
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
        return out << p.x << ' ' << p.y;
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
    
    int n; cin >> n;
    vector<Point> v(n);
    for (Point &p : v) {
        cin >> p;
    }
    sort(all(v));
    
    auto convex_hull = [](vector<Point> &points) {
        vector<Point> hull;
        for (Point &p : points) {
            while (ssize(hull) > 1 && cross(end(hull)[-2], end(hull)[-1], p) < 0)
                hull.pop_back();
            hull.push_back(p);
        }
        return hull;
    };
    vector<Point> upper_hull = convex_hull(v);
    reverse(all(v));
    vector<Point> lower_hull = convex_hull(v);
    
    cout << ssize(lower_hull) + ssize(upper_hull) - 2 << '\n';
    for (int i = 0; i < ssize(lower_hull); i++) {
        cout << lower_hull[i] << '\n';
    }
    for (int i = 1; i < ssize(upper_hull) - 1; i++) {
        cout << upper_hull[i] << '\n';
    }
    
    return 0;
}