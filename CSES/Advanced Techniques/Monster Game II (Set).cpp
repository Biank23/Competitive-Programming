#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
struct Line {
	ll m, b;
    mutable ld p; //we need to change p in the set
	bool operator<(const Line& o) const { //order by slope
        return m > o.m;
    }
	bool operator<(ld x) const {
        return p < x;
    }
    ld intersectX(const Line l) const {
        return ld(b - l.b) / (l.m - m);
    }
};
 
struct LineContainer : multiset<Line, less<>> {
	static constexpr ld INF = 1e18;
    bool intersect(iterator x, iterator y) {
        if (y == end()) {
            x->p = INF;
            return false;
        }
        if (x->m == y->m) { //parallel
            if (x->b < y->b) x->p = INF;
            else x->p = -INF;
        } else {
            x->p = x->intersectX(*y);
        }
        return x->p >= y->p;
    }
    void add(ll m, ll b) {
        auto next = emplace(m, b, 0);
        auto prev = next, curr = next;
        next++;
 
        while (intersect(curr, next)) {
            next = erase(next);
        }
        
        if (prev != begin() && intersect(--prev, curr)) {
            curr = erase(curr);
            intersect(prev, curr);
        }
        curr = prev;
        while (curr != begin() && (--prev)->p >= curr->p) {
            curr = erase(curr);
            intersect(prev, curr);
            curr = prev;
        }
    }
	ll query(ll x) {
		assert(!empty());
		Line l = *lower_bound(x);
		return l.m * x + l.b;
	}
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m0;
    cin >> n >> m0;
    
    vector<int> x(n), m(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    
    LineContainer dp;
    dp.add(m0, 0);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = dp.query(x[i]);
        dp.add(m[i], res);
    }
    cout << res << '\n';
    
    return 0;
}
