#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 5005;
 
ll dp[MAX_N][MAX_N], x[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        tot += x[i];
        dp[i + 1][i] = 0;
    }
    
    for (int r = 0; r < n; r++) {
        for (int l = r; l >= 0; l--) {
            dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
        }
    }
    
    // first + second = tot
    // first - second = dp[0][n - 1]
    // first = (tot + dp[0][n - 1]) / 2
    cout  << (tot + dp[0][n - 1]) / 2 << '\n';
    
    return 0;
}