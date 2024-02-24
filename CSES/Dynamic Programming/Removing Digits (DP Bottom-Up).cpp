#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 9;
const int INF = 1e9;
 
int dp[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        dp[i] = INF;
        while (num > 0) {
            int digit = num % 10;
            dp[i] = min(dp[i], dp[i - digit] + 1);
            num /= 10;
        }
    }
    cout << dp[n] << '\n';
    
    return 0;
}