#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    vector<ll> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= min(k, i); j++) {
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n - 1] << '\n';
    
    return 0;
}
