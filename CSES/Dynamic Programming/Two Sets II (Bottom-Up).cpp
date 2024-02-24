#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 500;
const int MAX_SUM = MAX_N * (MAX_N + 1) / 2;
const int MAX_TARGET =  MAX_SUM / 2 + 1;
const int MOD = 1e9 + 7; 
 
int dp[MAX_SUM];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << "0\n";
        return 0;
    }
    
    int target = sum / 2;
    dp[0] = 1;
    // n is in the subset we dont choose
    // we can add it and then divide by 2
    // the answer using the modular inverse
    for (int i = 1; i < n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] += dp[j - i];
            if (dp[j] >= MOD) {
                dp[j] -= MOD;
            }
        }
    }
    cout << dp[target] << '\n';
    
    return 0;
}