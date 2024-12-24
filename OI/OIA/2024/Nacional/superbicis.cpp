#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const ll INF = 1e18;

ll superbicis(vector<ll> &x, vector<ll> &y, vector<int> &c) {
    int n = sz(x);
    int T = 0;
    for (int i = 0; i < n; i++) {
        T += c[i];
    }
    assert(T % n == 0);
    int cant = T / n;
    vector<pair<ll, ll>> sobra, falta;
    for (int i = 0; i < n; i++) {
        while (c[i] > cant) sobra.emplace_back(x[i], y[i]), c[i]--;
        while (c[i] < cant) falta.emplace_back(x[i], y[i]), c[i]++;
    }
    assert(sz(sobra) == sz(falta));
    const int m = sz(sobra);
    vector<ll> dp(1 << m, INF);
    dp[0] = 0LL;
    for (int mask = 1; mask < 1 << m; mask++) {
        int p = __builtin_popcount(mask) - 1;
        for (int i = 0; i < m; i++) if (mask >> i & 1) {
            ll costo = abs(sobra[i].first - falta[p].first) + abs(sobra[i].second - falta[p].second);
            dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + costo);
        }
    }
    return dp[(1 << m) - 1];
}
