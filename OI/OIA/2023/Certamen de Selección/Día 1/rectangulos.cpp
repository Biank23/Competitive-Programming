#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define pb push_back

using vi = vector<int>;

struct Point {
    int x, y, idx;
};

const int INF = 2e9;

int consulta(int i, int W, int H);

int rectangulos(vi x, vi y) {
    vector<Point> p(sz(x));
    for (int i = 0; i < sz(p); i++) {
        p[i] = {x[i], y[i], i + 1};
    }
    sort(all(p), [](const Point &a, const Point &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
        
    });
    vector<vector<Point>> v;
    vi pos;
    for (int i = 0; i < sz(p); i++) {
        if (i == 0 || p[i].x != p[i - 1].x) {
            v.pb({p[i]});
            pos.pb(p[i].x);
        } else {
            v.back().pb(p[i]);
        }
    }
    int n = sz(v);
    vi pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + sz(v[i]);
    }
    auto findMid = [&](int l, int r) {
        int tot = pref[r+1] - pref[l];
        int target = tot / 2;
        int lo = l, hi = r;
        while (lo + 1 < hi) {
            int mid = (lo+hi)/2;
            if (pref[mid+1] - pref[l] >= target){
                hi = mid;
            } else {
                lo = mid;
            }
        }
        int diffHi = abs(tot - 2 * (pref[hi+1] - pref[l]));
        int diffLo = abs(tot - 2 * (pref[lo+1] - pref[l]));
        if (diffHi < diffLo) {
            return hi;
        } else {
            return lo;
        }
    };
    
    int l = -1, r = n - 1;
    int i = p[0].idx;
    while (l + 1 < r) {
        int m = findMid(l + 1,r);
        int diff = max(1, 2 * (pos[m] - pos[0]));
        if (consulta(i, diff, INF)) {
            r = m;
        } else {
            l = m;
        }
    }
    
    vector<Point> c = v[r];
    l = -1, r = sz(c) - 1;
    i = c[0].idx;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        int diff = max(1, 2 * (c[m].y - c[0].y));
        if (consulta(i, 1, diff)) {
            r = m;
        } else {
            l = m;
        }
    }
    
    return c[r].idx;
}
