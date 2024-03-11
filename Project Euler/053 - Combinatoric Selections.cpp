#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

const int INF = 1e6 + 1;
const int N = 101;

int dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[0][0] = 1;
    int res = 0;
    for (int n = 1; n <= 100; n++) {
        dp[n][0] = dp[n][n] = 1;
        for (int k = 1; k < n; k++) {
            dp[n][k] = dp[n - 1][k] + dp[n - 1][k - 1];
            if (dp[n][k] >= INF) {
                dp[n][k] = INF;
                res++;
            }
        }
    }
    cout << res << '\n';

    return 0;
}