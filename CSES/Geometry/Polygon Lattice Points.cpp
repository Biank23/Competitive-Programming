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
    
    int n;
    cin >> n;
    vector<Point> vertex(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> vertex[i];
    }
    vertex[n] = vertex[0];
    
    ll area = 0, boundary = 0;
    for (int i = 0; i < n; i++) {
        area += vertex[i] ^ vertex[i + 1];
        Point diff = vertex[i] - vertex[i + 1];
        boundary += gcd(diff.x, diff.y);
    }
    //pick's theorem
    ll inside=(abs(area)-boundary)/2+1;
    cout << inside << ' ' << boundary << '\n';
    
    return 0;
}