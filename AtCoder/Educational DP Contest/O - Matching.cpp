#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 21;
const int MOD = 1e9+7;

bool a[MAX_N][MAX_N];
int dp[1<<MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    dp[0] = 1;	
    for (int mask = 1; mask < 1<<n; mask++) {
        int i = __builtin_popcount(mask) - 1;
        for (int j = 0; j < n; j++) {
            if (mask>>j & 1 && a[i][j]) {
                dp[mask] += dp[mask ^ (1<<j)];
                if (dp[mask] >= MOD) dp[mask] -= MOD; 
            }
        }
    }
    cout << dp[(1<<n) - 1] << '\n';
    
    return 0;
}
