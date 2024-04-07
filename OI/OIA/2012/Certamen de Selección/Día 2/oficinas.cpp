#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ii = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;

const ll INF = 1e18;

string solve(int l, int r, vector<vi> &opt, vi &id) {
    if (l > r) return "";
    int m = opt[l][r];
    return "(" + solve(l, m - 1, opt, id) + to_string(id[m]) + solve(m + 1, r, opt, id) + ")";
}

int main() {
    freopen("oficinas.in", "r", stdin);
	freopen("oficinas.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<ii> v(n);
    for (auto &[a, b] : v) {
        cin >> a >> b;
    }
    sort(all(v));
    vi c(n + 1), id(n + 1);
    vll pref(n + 2);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        tie(id[i], c[i]) = v[i - 1];
        pref[i + 1] = pref[i] + c[i];
    }
    vector<vll> dp(n + 2, vll(n + 2, INF));
    vector<vi> opt(n + 2, vi(n + 2));
    for (int i = 0; i <= n; i++) {
        dp[i + 1][i] = c[i];
        opt[i + 1][i] = i;
    }
    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            ll sum = pref[r + 1] - pref[l];
            int mini = max(opt[l][r-1], l);
            int maxi = min(opt[l + 1][r], r);
            for (int i = mini; i <= maxi; i++) {
                ll val = dp[l][i - 1] + dp[i + 1][r] + sum - c[i];
                if (val < dp[l][r]) {
                    dp[l][r] = val;
                    opt[l][r] = i;
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
    cout << solve(1, n, opt, id) << '\n';
    
    return 0;
}
