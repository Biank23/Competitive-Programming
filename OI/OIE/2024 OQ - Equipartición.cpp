#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x),end(x)

using ll = long long;
using ii = pair<int, int>;
#define fst first
#define snd second

struct Point {
    int x, y, v;
    friend ostream &operator<<(ostream &os, Point p) {
        return os << '(' << p.x << ", " << p.y << ')';
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<Point> p(n);
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y >> p[i].v;
            tot += p[i].v;
        }
        auto findMid = [&]() {
            sort(all(p), [](const Point &a, const Point &b) {
                return a.x < b.x;
            });
            ll sum = 0;
            int i = -1;
            while (i < n - 1 && 2 * sum <= tot) {
                sum += p[++i].v;
            }
            for (Point &a : p) swap(a.x, a.y);
            if (i > 0) return ii{p[i - 1].y, p[i].y - p[i - 1].y};
            else return ii{0, 0};
        };
        ii rangeX = findMid();
        ii rangeY = findMid();
        ll sum[4] = {0};
        auto quad = [&](Point a) {
            return 2 * (a.x > rangeX.fst) + (a.y > rangeY.fst);
        };
        for (int i = 0; i < n; i++) {
            sum[quad(p[i])] += p[i].v;
        }
        bool flag = true;
        for (int i = 1; i < 4; i++) {
            if (sum[i] != sum[i - 1]) flag = false;
        }
        if (flag) {
            cout << (ll) rangeX.snd * rangeY.snd << '\n';
        } else {
            cout << "0\n";
        }
    }
    
    return 0;
}
