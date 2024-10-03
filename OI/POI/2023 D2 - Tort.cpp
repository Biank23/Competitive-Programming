#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ii = pair<int, int>;
using ll = long long;
 
const double EPS = 1e-6;
const double pi = acos(-1);

inline double angle(ii p) {
    return atan2(p.second, p.first);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<ii> p(n + 2);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    p[n] = p[0], p[n + 1] = p[1];
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        total += p[i].first * ll(p[i + 1].second - p[i - 1].second);
    }
    total = abs(total);
    vector<pair<ii, int>> vec(n + 2);
    for (int i = 0; i < n; i++) {
        vec[i] = {p[i], i % 2 ? 1 : -1};
    }
    vec[n] = {{0, 1}, 0};
    vec[n + 1] = {{1, 0}, 0};
    sort(all(vec), [](const pair<ii, int> &a, const pair<ii, int> &b){
        return angle(a.first) < angle(b.first);
    });
    ll A = 0, B = 0, C = 0;
    #define area(alpha) (abs(A * tan(alpha) + B - C * tan(pi/2.0 - alpha)))
    for (int i = 0; i < n + 2; i++) {
        auto [point, sign] = vec[i];
        A += 1LL * point.first * point.first * sign;
    }
    int j = 0;
    vector<double> res(k);
    for (int i = 1; i <= n; i++) {
        auto [point, sign] = vec[i];
        A -= 1LL * point.first * point.first * sign;
        B += 2LL * point.first * point.second * sign;
        C += 1LL * point.second * point.second * sign;
        double target = double(j + 1) / double(k + 1) * total;
        while (j < k && area(angle(vec[i + 1].first)) >= target) {
            double lo = angle(vec[i].first), hi = angle(vec[i + 1].first);
            while (hi - lo > EPS) {
                double mid = (lo + hi) / 2.0;
                if (area(mid) >= target) hi = mid;
                else lo = mid;
            }
            res[j++] = hi;
            target = double(j + 1) / double(k + 1) * total;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << setprecision(15) << fixed << cos(res[i]) << ' ' << sin(res[i]) << '\n';
    }
    
    return 0;
}
