#include <bits/stdc++.h>

using namespace std;

using ld = double;

inline ld sq(ld x) {
    return x * x;
}

struct Point {
    ld x, y;
    Point(ld _x = 0.0, ld _y = 0.0) : x(_x), y(_y) {}
    Point operator-(const Point &o) {
        return {x - o.x, y - o.y};
    }
    ld abs() {
        return sqrt(sq(x) + sq(y));
    }
    ld operator^(const Point &o) { //cross
        return x * o.y - y * o.x;
    }
    friend istream& operator>>(istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
};

const ld EPS = 1e-3;
const ld PI = acos(-1.0);

ld gcd(ld a, ld b) {
    if (fabs(b) < EPS) return a;
    return gcd(b, fmod(a, b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    Point p[4];
    for (int i = 0; i < 3; i++) {
        cin >> p[i];
    }
    p[3] = p[0];
    
    ld side[3];
    ld area = 0.0;
    ld radius = 1.0;
    for (int i = 0; i < 3; i++) {
        side[i] = (p[i] - p[i + 1]).abs();
        area += p[i] ^ p[i + 1];
        radius *= side[i];
    }
    area = abs(area) / 2.0;
    radius /= 4.0 * area;
    
    ld angle[3];
    for (int i = 0; i < 2; i++) {
        angle[i] = acos(max(1 - sq(side[i]) / (2 * sq(radius)), -1.0));
    }
    angle[2] = 2 * PI - angle[0] - angle[1];
    
    ld alpha = gcd(angle[0], gcd(angle[1], angle[2]));

    cout << setprecision(12) << fixed << sq(radius) * sin(alpha) * (PI / alpha) << '\n';
    return 0;
}