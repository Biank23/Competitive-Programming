#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define eb emplace_back
 
typedef long long ll;
 
struct Point {
    ll x, y;
};
 
inline ll dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<Point> v(n);
    for (Point &p : v) {
        cin >> p.x >> p.y;
    }
    sort(all(v), [](const Point &lhs, const Point &rhs){
        return lhs.x < rhs.x;
    });
    
    const auto cmp = [](const Point &lhs, const Point &rhs) {
        if (lhs.y != rhs.y) return lhs.y < rhs.y;
        return lhs.x < rhs.x;
    };
    set<Point, decltype(cmp)> s;
    ll res = dist(v[0], v[1]);
    for (Point p : v) {
        ll d = (ll)ceil(sqrt(res));
        for (auto it = s.lower_bound({p.x, p.y - d}); it != s.end() && it->y <= p.y + d; it++) {
            while (it != s.end() && it->x < p.x - d) it = s.erase(it);
            if (it == s.end()) break;
            res = min(res, dist(p, *it));
        }
        s.insert(p);
    }
    
    cout << res << '\n';
    
    
    return 0;
}
