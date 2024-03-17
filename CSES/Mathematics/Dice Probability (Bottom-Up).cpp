#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 101, MAX_X = 601;
 
double dp[MAX_N][MAX_X];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= 6 * i; j++) {
            for (int k = 1; k <= min(j, 6); k++) {
                dp[i][j] += dp[i - 1][j - k] / 6.0;
            }
        }
    }
    
    double ans = 0.0;
    for (int i = a; i <= b; i++) {
        ans += dp[n][i];
    }
    
    cout << setprecision(6) << fixed << ans << '\n';
    
    return 0;
}
