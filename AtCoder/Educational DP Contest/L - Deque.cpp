#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_N = 3001;

ll dp[MAX_N][MAX_N], a[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    
    cout << dp[0][n - 1] << '\n';
    
    return 0;
}
