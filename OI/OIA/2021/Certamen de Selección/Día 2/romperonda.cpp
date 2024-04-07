#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

const int MAX_N = 6060;
const int MAX_K = 60;
const int MOD = 16;
const int INF = 1e9;

int dp[MAX_N][MAX_K][MOD];

int getDP(vector<int> &ronda, int k, bool flag = false, int s = 0) {
    int n = sz(ronda);
    for (int a = 0; a < n; a++) {
        for (int b = 0; b <= k; b++) {
            for (int c = 0; c < MOD; c++) {
                dp[a][b][c] = -INF;
            }
        }
    }
    int f = (ronda[0] + s) % MOD;
    dp[0][1][0] = f * f;
    if (flag) dp[0][0][f] = 0;
    for (int a = 1; a < n; a++) {
        for (int b = 0; b <= k; b++) {
            for (int c = 0; c < MOD; c++) {
                int pc = (c - ronda[a]) % MOD;
                if (pc < 0) pc += MOD;
                dp[a][b][c] = dp[a - 1][b][pc];
                if (b) dp[a][b][0] = max(dp[a][b][0], dp[a - 1][b - 1][pc] + c * c);
            }
        }
    }
    return dp[n - 1][k][s];
}

vector<int> romperonda(vector<int> &ronda, int k) {
    int ans = -INF;
    for (int i = 0; i < MOD; i++) {
        ans = max(ans, getDP(ronda, k, true, i));
    }
    return {ans, getDP(ronda, k)};
}
