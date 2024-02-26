#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define pb push_back
 
typedef long long ll;
 
struct Point {
    ll x, y;
    bool operator<(const Point &o) {
        return x < o.x;
    }
};
 
const ll INF = LLONG_MAX;
 
inline ll dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
 
vector<Point> v;
 
bool cmp(const Point &lhs, const Point &rhs) {
    return lhs.y < rhs.y;
}
 
ll solve(int l, int r) { // [l, r]
    if (r - l < 1) return INF;
    int m = (l + r) / 2;
    ll res = min(solve(l, m), solve(m + 1, r));
    ll d = (ll)ceil(sqrt(res));
    vector<Point> candidates;
    ll line = (v[m].x + v[m + 1].x) / 2;
    for (int i = m + 1; i <= r && v[i].x - line < d; i++) {
        candidates.pb(v[i]);
    }
    sort(all(candidates), cmp);
    for (int i = m; i >= l && line - v[i].x < d; i--) {
        Point target = v[i]; target.y -= d + 1;
        int j = int(lower_bound(all(candidates), target, cmp) - candidates.begin());
        while (j < ssize(candidates) && candidates[j].y <= v[i].y + d) {
            res = min(res, dist(v[i], candidates[j]));
            j++;
        }
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    v.resize(n);
    for (Point &p : v) cin >> p.x >> p.y;
    sort(all(v));
    cout << solve(0, n - 1) << '\n';
    
    
    return 0;
}