#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9 + 20;
 
struct STree {
    int n;
    vector<int> st;
    STree(int sz) : n(sz), st(2*n, INF) {}
    void init(vector<int> &v) {
        for (int i = 0; i < n; i++) {
			st[i + n] = v[i];
		}
		for (int i = n - 1; i > 0; i--) {
			st[i] = min(st[2 * i], st[2 * i + 1]);
		}
    }
    void update(int i, int v) {
        for (st[i += n] = v; i /= 2;) {
            st[i] = min(st[2 * i], st[2 * i + 1]);
        }
    }
    int query(int l, int r) {
        int res = INF;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) res = min(res, st[l++]);
            if (r&1) res = min(st[--r], res);
        }
        return res;
    }
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
    vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
        int v;
		cin >> v;
		l[i] = v - i;
        r[i] = v + i;
	}
    STree left(n), right(n);
    left.init(l), right.init(r);
	
	while (q--) {
		int t, k;
		cin >> t >> k;
		--k;
		
		if (t == 1) {
			int v;
            cin >> v;
            left.update(k, v - k);
            right.update(k, v + k);
		} else {
            int bestLeft = left.query(0, k) + k;
			int bestRight = right.query(k, n) - k;
			cout << min(bestLeft, bestRight) << '\n';
		}
	}
}