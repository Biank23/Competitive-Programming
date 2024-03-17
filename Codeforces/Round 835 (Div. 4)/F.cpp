#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define forn(i,n) for(int i=0;i<int(n);i++)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        ll n, c, d;
        cin >> n >> c >> d;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a), greater<ll>());
        a.resize(d + 2, 0);
        vector<ll> p(d + 3, 0);
        for (int i = 0; i < d + 2; i++) {
            p[i + 1] = p[i] + a[i];
        }
        ll l = -1, r = d + 2;
        auto check = [&](ll k) {
            k++;
            return c <= p[k] * (d / k) + p[d % k];
        };
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (check(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l == -1) cout << "Impossible\n";
        else if (l == d + 1) cout << "Infinity\n";
        else cout << l << '\n';
        
    }
    
    return 0;
}
