#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5+1;
const int MOD = 1e9+7;

int dp[MAX_N], pref[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j <= k; j++) {
            pref[j] = dp[j];
            if (j > 0) {
                pref[j] += pref[j - 1];
                if (pref[j] >= MOD) pref[j] -= MOD;
            }
            dp[j] = pref[j];
            if (j > x) {
                dp[j] -= pref[j - x - 1];
                if (dp[j] < 0) dp[j] += MOD;
            }
        }
    }
    
    cout << dp[k] << '\n';
    
    return 0;
}
