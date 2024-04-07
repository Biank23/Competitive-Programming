#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

const int INF = 2e9 + 20;

int sendero(int B, int G, int N, string &baldosas) {
    int n = sz(baldosas);
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    vector<int> costos = {B, G, N};
    const string tipos = "BGN";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (baldosas[i] != tipos[j] && baldosas[i] != 'R') {
                dp[i + 1][j] = INF;
            } else {
                dp[i + 1][j] = min(dp[i][(j + 1) % 3], dp[i][(j + 2) % 3]);
                if (baldosas[i] == 'R' && dp[i + 1][j] != INF) {
                    dp[i + 1][j] += costos[j];
                }
            }
        }
    }
    auto it = min_element(all(dp[n]));
    int j = int(it - begin(dp[n]));
    for (int i = n - 1; i >= 0; i--) {
        baldosas[i] = tipos[j];
        if (dp[i][(j + 1) % 3] < dp[i][(j + 2) % 3]) {
            j = (j + 1) % 3;
        } else {
            j = (j + 2) % 3;
        }
    }
    return *it;
}
