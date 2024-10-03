#include <bits/stdc++.h>

using namespace std;

const int SZ = 1 << 20;

using ll = long long;
using ii = pair<ll, ll>;
#define fst first
#define snd second

ii st[2 * SZ];

void update(int p, ll v) {
    p += SZ;
    st[p].fst += v;
    st[p].snd += (p - SZ) * v;
    while (p /= 2) {
        st[p].fst = st[2 * p].fst + st[2 * p + 1].fst;
        st[p].snd = st[2 * p].snd + st[2 * p + 1].snd;
    }
}

ll query(ll x) {
    int u = 1;
    ll res = 0;
    while (u < SZ) {
        u = 2 * u + 1;
        if (st[u].fst < x) {
            x -= st[u].fst;
            res += st[u].snd;
            u--;
        }
    }
    res += min((u - SZ) * x, st[u].snd);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> x(n), a(n), y(m), b(m), c(m);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i] >> b[i] >> c[i];
    }
    int i = 0, j = 0;
    ll tot = 0, ans = 0;
    while (i < n || j < m) {
        int pos;
        if (j >= m || (i < n && x[i] < y[j])) {
            tot += a[i];
            pos = x[i];
            i++;
        } else {
            update(c[j], b[j]);
            pos = y[j];
            j++;
        }
        ans = max(ans, query(tot) - (ll) pos * p);
    }
    cout << ans << '\n';
    
    return 0;
}