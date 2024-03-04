#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_N = 16;

ll val[MAX_N][MAX_N], cost[1<<MAX_N], dp[1<<MAX_N];  

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val[i][j];
        }
    }

    for (int mask = 0; mask < 1<<n; mask++) {
        for (int i = 0; i < n; i++) if (mask>>i & 1) {
            for (int j = 0; j < i; j++) if (mask>>j & 1) {
                cost[mask] += val[i][j];
            }
        }
        dp[mask] = cost[mask];
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            dp[mask] = max(dp[mask], dp[mask ^ submask] + cost[submask]);
        }
    }
    
    cout << dp[(1<<n) - 1] << '\n';
    
    return 0;
}
