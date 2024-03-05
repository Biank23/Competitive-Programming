#include <bits/stdc++.h>
 
using namespace std;

using ll = long long;

const int MAX_N = 2e5 + 1;
const int MAX_K = 18;
const int MAX_D = 30;

int st[MAX_K][MAX_N];
int n;
 
inline int log(int i) {
    return 31 - __builtin_clz(i);
}

void initSparseTable(vector<int> &v, int d) {
    for (int i = 0; i < n; i++) {
        if (log(v[i]) == d) st[0][i] = v[i];
        else st[0][i] = 1 << (d + 1);
    }
    int step = 1;
    for (int i = 0; i < MAX_K - 1; i++) {
        for (int j = 0; j < n - step; j++) {
            st[i + 1][j] = min(st[i][j], st[i][j + step]);
        }
        step *= 2;
    }
}

ll mini(int l, int r) { //[l, r)
    int j = log(r - l);
    return min(st[j][l], st[j][r - (1 << j)]);
}

ll pref[MAX_N];

void initPrefix(vector<int> &v, int d) {
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        if (log(v[i]) == d) pref[i + 1] += v[i];
    }
}

ll sum(int l, int r) { //[l, r)
    return pref[r] - pref[l];
}

struct Query {
    int l, r;
    ll smallestMissingSum = 1;
    bool flag = false;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<Query> v(q);
    for (int i = 0; i < q; i++) {
        cin >> v[i].l >> v[i].r;
        --v[i].l;
    }

    for (int d = 0; d < MAX_D; d++) {
        initSparseTable(x, d);
        initPrefix(x, d);
        for (int i = 0; i < q; i++) {
            if (v[i].flag) continue;
            if (mini(v[i].l, v[i].r) <= v[i].smallestMissingSum) {
                v[i].smallestMissingSum += sum(v[i].l, v[i].r);
            } else {
                v[i].flag = true;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << v[i].smallestMissingSum << '\n';
    }
	
	return 0;
}