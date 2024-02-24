#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_X = 1e6 + 9;
const int INF = 1e9;
 
int dp[MAX_X];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    for (int i = 1; i <= x; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = c; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }
    if (dp[x] == INF) dp[x] = -1;
    
    cout << dp[x] << '\n';
    
    
    return 0;
}