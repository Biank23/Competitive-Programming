#include <bits/stdc++.h>

using namespace std;

using ld = long double;
const int MAX_N = 305;

ld dp[MAX_N][MAX_N][MAX_N];
int freq[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        freq[a - 1]++;
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            for (int k = 0; k <= n - i - j; k++) {
                if (i == 0 && j == 0 && k == 0) continue;
                double s = i + j + k;
                dp[i][j][k] += n / s;
                if (i > 0) {
                    dp[i][j][k] += i / s * dp[i - 1][j + 1][k];
                }
                if (j > 0) {
                    dp[i][j][k] += j / s * dp[i][j - 1][k + 1];
                }
                if (k > 0) {
                    dp[i][j][k] += k / s * dp[i][j][k - 1];
                }
            }
        }
    }
    cout << setprecision(16) << dp[freq[2]][freq[1]][freq[0]] << "\n";
    return 0;
}

