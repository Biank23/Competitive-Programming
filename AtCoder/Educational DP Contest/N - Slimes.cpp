#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_N = 501;
const ll INF = 1e18;

ll a[MAX_N], pref[MAX_N], dp[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            dp[l][r] = INF;
            for (int m = l; m <= r; m++) {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
            dp[l][r] += pref[r + 1] - pref[l];
        }
    }
    
    cout << dp[0][n-1] << '\n';
    
    return 0;
}
