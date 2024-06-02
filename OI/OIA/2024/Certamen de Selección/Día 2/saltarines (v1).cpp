#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

const int MAX_N = 309;
const int MAX_K = 2024;
const int MAX_C = MAX_N;

ll dp[MAX_C][MAX_K];
ll pref[MAX_N];

ll saltarines(int K, vector<int> &elegancias, vector<int> &ubicaciones) {
    int n = sz(elegancias), c = sz(ubicaciones);
    sort(all(ubicaciones));
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + elegancias[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = c - 1; j >= 0; j--) {
            int d = i - ubicaciones[j];
            if (d < 0) continue;
            ll w = pref[i] - pref[ubicaciones[j]];
            for (int k = 0; k <= K - d; k++) {
                dp[j + 1][k + d] = max(dp[j + 1][k + d], dp[j][k] + w);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= K; i++) {
        ans = max(ans, dp[c][i]);
    }
    return ans;
}
