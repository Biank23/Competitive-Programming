#include "coreputer.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;

#define all(x) x.begin(), x.end()
#define subvec(l, r) vi(begin(p) + l, begin(p) + r)

ii binary(int l, int r, const vi &p) {
	ii ans = {r, 0};
	while (r - l > 1) {
		int m = (l + r) / 2;
		int call = run_diagnostic(subvec(0, m));
		if (call != -1) {
            r = m;
			ans = {r, call};
		} else {
			l = m;
		}
	}
	return ans;
}

int solve(vi g, vi p, vi &m) {
	int count = 0;
    for (int i : p) {
        g.push_back(i);
        if (run_diagnostic(g) == 1) {
            m[i] = 1;
            count++;
        }
        g.pop_back();
    }
    return count;
}

vector<int> malfunctioning_cores(int n) {
	vector<int> p(n), m(n, 0);
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	ii ans = binary(0, n, p);
	int cut = ans.first;
	bool parity = ans.second;
	if (cut == n) {
        m.back() = 1;
        return m;
	}
	
    int count = 0;
    count += solve(subvec(cut, n), subvec(0, cut - 1), m);
    m[cut - 1] = 1;
    count++;
    count += solve(subvec(0, cut - parity), subvec(cut, n - 1), m);
    if (count % 2 != parity) {
        m.back() = 1;
    }
    return m;
}
