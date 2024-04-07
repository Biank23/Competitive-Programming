#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 4004;

#define sz(x) int(x.size())

int dp[MAX_N][MAX_N];

int nivelacion(string palabra) {
    int n = sz(palabra);
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            if (palabra[l] == palabra[r]) {
                dp[l][r] = dp[l + 1][r - 1];
            } else {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
            }
        }
    }
    return dp[0][n - 1];
}
