#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    
    vector<ll> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    
    cout << dp[x] << '\n'; 
    
    return 0;
}
