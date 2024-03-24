#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

const ll INF = 1e18;

ll ceilDiv(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, k, m, r;
        cin >> n >> k >> m >> r;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto check = [&](ll x) {
            ll need = 0;
            for (int i = 0; i < n; i++) {
                ll val = a[i] - x * r;
                ll diff = k - val;
                if (diff > 0) {
                    need += ceilDiv(diff, m + r);
                    if (need > x) return false;
                }
            }
            return true;
        };
        ll ans = INF;
        for (int i = 0; i < n; i++) {
            ll lo = -1, hi = ceilDiv(INF, n);
            while (lo + 1 < hi) {
                ll mid = (lo + hi) / 2;
                if (check(mid * n + i)) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            ans = min(ans, hi * n + i);
        }
        cout << ans << '\n';
    }
    
    return 0;
}
