#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
struct Point {
    ll x, y;
    Point operator+(const Point &o) {
        return {x + o.x, y + o.y};
    }
    Point operator-(const Point &o) {
        return {x - o.x, y - o.y};
    }
    ll operator^(const Point &o) { //cross
        return x * o.y - y * o.x;
    }
    ll operator*(const Point &o) { //point
        return x * o.x + y * o.y;
    }
    friend ostream &operator<<(ostream &os, const Point &p) {
        return os << '(' << p.x << ", " << p.y << ')';
    }
    friend istream &operator>>(istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
};
 
using Segment = pair<Point, Point>;
#define fst first
#define snd second
 
int loc(Segment s, Point p) {
    ll dir = (p-s.fst)^(s.snd-s.fst);
    return (dir > 0) - (dir < 0);
}
 
bool onSegment(Point p, Segment s) {
    return !loc(s, p) && p.x >= min(s.fst.x, s.snd.x) && p.x <= max(s.fst.x, s.snd.x) && 
                         p.y >= min(s.fst.y, s.snd.y) && p.y <= max(s.fst.y, s.snd.y);
}
 
bool intersect(Segment S1, Segment S2) {
    return loc(S1, S2.fst) != loc(S1, S2.snd) && loc(S2, S1.fst) != loc(S2, S1.snd);
}
 
const Point INF{ll(1e9 + 7), ll(1e9 + 9)};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    
    vector<Point> vertex(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> vertex[i];
    }
    vertex[n] = vertex[0];
    
    while (m--) {
        int x, y;
        cin >> x >> y;
        Point p{x, y};
        Segment l{p, INF};
        bool flag = false;
        int count = 0;
        for (int i = 0; i < n; i++) {
            Segment s = {vertex[i], vertex[i + 1]};
            if (onSegment(p, s)) {
                flag = true;
                break;
            }
            if (intersect(s, l)) count++;
        }
        
        if (flag) {
            cout << "BOUNDARY\n";
        } else if (count % 2 == 1) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
    
    return 0;
}