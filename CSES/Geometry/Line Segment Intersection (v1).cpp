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
 
struct Segment {
    Point p, q, d;
    friend istream &operator>>(istream &is, Segment &s) {
        is >> s.p >> s.q;
        s.d = s.q - s.p;
        return is;
    }
};
 
bool solve() {
    Segment s[2];
    for (int i = 0; i < 2; i++) {
        cin >> s[i];
    }
    if ((s[0].d ^ s[1].d) == 0) { //same direction
        if (((s[1].p - s[0].p) ^ s[1].d) != 0) {
            return false;
        }
        for (int i = 0; i < 2; i++) {
            if (max(s[i].p.x, s[i].q.x) < min(s[1 - i].p.x, s[1 - i].q.x)) {
                return false;
            }
            if (max(s[i].p.y, s[i].q.y) < min(s[1 - i].p.y, s[1 - i].q.y)) {
                return false;
            }
        }
        return true;
    }
    //only one intersection point
    for (int i = 0; i < 2; i++) {
        ll num = (s[i].p - s[1 - i].p) ^ s[i].d;
        ll den = s[1 - i].d ^ s[i].d;
        //num/den < 0 || num/den > 1
        if (den < 0) num *= -1, den *= -1;
        if (num < 0 || num > den) {
            return false;
        }
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}