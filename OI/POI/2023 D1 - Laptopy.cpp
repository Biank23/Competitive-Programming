#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
using vll = vector<ll>;

vll getVal(vll &v, ll d) {
    int s = sz(v);
    vector<vector<pair<ll, ll>>> dp(s + 1, vector<pair<ll, ll>>(s + 1, {0, 0}));
    for (int i = 0; i < s; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i + 1][j] = {dp[i][j].first + v[i] / d, v[i] % d};
            if (j > 0) {
                auto [cant, remain] = dp[i][j - 1];
                remain += v[i];
                cant += remain / d, remain %= d;
                dp[i + 1][j] = max(dp[i + 1][j], {cant, remain});
            }
        }
    }
    vll val(s + 1);
    for (int i = 0; i <= s; i++) val[i] = dp[s][i].first;
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q, l; ll d, w;
    cin >> n >> q >> d >> l >> w;
    vector<vll> b(l);
    for (int i = 0; i < n; i++) {
        int k; ll p;
        cin >> k >> p;
        b[k - 1].push_back(p);
    }
    vector<vll> v(l);
    for (int i = 0; i < l; i++) {
        sort(all(b[i]));
        ll prev = 0;
        for (ll curr : b[i]) {
            v[i].push_back(curr - prev);
            prev = curr + d;
        }
        v[i].push_back(w - prev);
    }
    vector<vll> val(l);
    for (int i = 0; i < l; i++) {
        val[i] = getVal(v[i], d);
    }
    vector<vll> dp(l + 1, vll(n + 1, 0));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < sz(val[i]) && j + k <= n; k++) {
                dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + val[i][k]);
            }
        }
    }
    while (q--) {
        ll m;
        cin >> m;
        int pos = int(lower_bound(all(dp[l]), m) - begin(dp[l]));
        if (pos == n + 1) cout << "-1\n";
        else cout << pos << '\n';
    }
    
    return 0;
}