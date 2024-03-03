#include <bits/stdc++.h>
 
using namespace std;
 
const int BITS = 20;
const int FLIP = (1<<BITS) - 1;
 
int dp[1<<BITS][2];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]][0]++, dp[a[i]][1]++;
    }
    
    for (int i = 0; i < BITS; i++) {
        for (int mask = 0; mask < 1<<BITS; mask++) {
            int b = mask>>i&1;
            dp[mask^(1<<i)][b] += dp[mask][b];
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << dp[a[i]][0] << ' '
             << dp[a[i]][1] << ' '
             << n - dp[a[i]^FLIP][0] << '\n';
    }
    
    return 0;
}