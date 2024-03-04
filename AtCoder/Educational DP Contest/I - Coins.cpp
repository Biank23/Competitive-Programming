#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    
    vector<double> dp(n + 1, 0.0);
    dp[0] = 1.0;

    for (int i = 0; i < n; i++) {
        double p;
        cin >> p;
        for (int j = n; j >= 0; j--) {
            dp[j] *= 1.0 - p;
            if (j > 0) dp[j] += dp[j - 1] * p;
        }
    }
    
    double res = 0;
    for (int i = n / 2 + 1; i <= n; i++) {
        res += dp[i];
    }
    cout << setprecision(10) << res << '\n';
    
    return 0;
}
