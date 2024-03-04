#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_N = 2e5;

ll st[2 * MAX_N];
int n;

void update(int p, ll v) {
    p += n;
    if (st[p] < v) {
        st[p] = v;
        while (p /= 2) {
            st[p] = max(st[2 * p], st[2 * p + 1]);
        }
    }
}

ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l&1) res = max(res, st[l++]);
        if (r&1) res = max(st[--r], res);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> v(n);
    for (int &x : v) {
        cin >> x;
        --x;
    }
    for (int &i : v) {
        int x; cin >> x;
        update(i, query(0, i) + x);
    }
    cout << query(0, n) << '\n';
    return 0;
}
