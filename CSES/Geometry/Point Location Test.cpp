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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        Point p[3];
        for (int i = 0; i < 3; i++) {
            cin >> p[i];
        }
        ll prod = (p[1] - p[0]) ^ (p[2] - p[0]);
        if (prod < 0) {
            cout << "RIGHT\n";
        } else if (prod > 0) {
            cout << "LEFT\n";
        } else {
            cout << "TOUCH\n";
        }
    }
    
    return 0;
}