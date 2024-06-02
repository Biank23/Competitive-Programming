#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const ll INF = 1e18;

inline void chmax(ll &x, ll v) {
    if (v > x) x = v;
}

ll saltarines(int K, vector<int> &elegancias, vector<int> &ubicaciones) {
    int n = sz(elegancias), c = sz(ubicaciones);
    vector<bool> conejos(n + 1, false);
    for (int i = 0; i < c; i++) {
        conejos[ubicaciones[i]] = true;
    }
    vector<vector<ll>> dp(c + 2, vector<ll>(K + 1, -INF));
    dp[conejos[0]][K] = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<ll>> nextDP(c + 2, vector<ll>(K + 1, -INF));
        ll w = 0;
        for (int k = 0; k <= c; k++, w += elegancias[i]) {
            for (int q = k; q <= K; q++) {
                chmax(nextDP[k + conejos[i + 1]][q - k], dp[k][q] + w);
            }
            if (k == 0) continue;
            for (int q = k - 1; q <= K; q++) {
                chmax(nextDP[k + conejos[i + 1] - 1][q - k + 1], dp[k][q] + w - elegancias[i]);
            }
        }
        swap(dp, nextDP);
    }
    ll ans = -INF;
    for (int i = 0; i <= K; i++) {
        ans = max({ans, dp[0][i], dp[1][i]});
    }
    return ans;
}
