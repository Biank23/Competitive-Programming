#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_X = 1e6 + 9;
const int MAX_N = 1000;
 
int dp[MAX_X], h[MAX_N], s[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    cout << dp[x] << '\n';
    
    return 0;
}