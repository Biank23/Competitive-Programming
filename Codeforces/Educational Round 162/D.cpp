#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
using vi = vector<int>;

const int INF = 1e9;

vi solve(vi &a) {
    int n = sz(a);
    vi sig(n);
    sig[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != a[i + 1]) {
            sig[i] = i + 1;
        } else {
            sig[i] = sig[i + 1];
        }
    }
    vector<ll> pref(n + 1);
    pref[0] = 0LL;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    vi ans(n);
    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(all(pref), a[i] + pref[i + 1]) - begin(pref)) - 1;
        if (j != i + 1) j = max(j, sig[i + 1]);
        if (j == n) ans[i] = INF;
        else ans[i] = j - i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vi pref = solve(a);
        reverse(all(a));
        vi suff = solve(a);
        reverse(all(suff));
        for (int i = 0; i < n; i++) {
            ll ans = min(pref[i], suff[i]);
            if (ans == INF) cout << "-1 ";
            else cout << ans << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}