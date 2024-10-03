#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 305;
 
using ll = long long;
 
const ll INF = 1e18;
 
ll dp[MAX_N][MAX_N][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> h(n + 2);
    for (int i = 2; i < n + 2; i++) {
        cin >> h[i];
    }
    for (int i = 2; i < n + 2; i++) {
        for (int j = 0; j <= h[i - 1]; j++) {
            for (int k = 0; k <= h[i]; k++) {
                dp[i][j][k] = INF;
                if (k != 0) dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1] + 3LL);
                if (j != 0 && k != 0) dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k - 1] + 5LL);
                if (j >= k && h[i - 2] >= k) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][h[i - 2] - k][j - k] + 7LL * k);
            }
        }
    }
    cout << dp[n + 1][h[n]][h[n + 1]] << '\n';
    
    return 0;
}