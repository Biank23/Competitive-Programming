#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using vll = vector<ll>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<vll> dp(n + 1, vll(3, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            int val;
            cin >> val;
            dp[i][j] = val + max(dp[i - 1][(j + 1) % 3],
                                 dp[i - 1][(j + 2) % 3]);
        }
    }
    
    cout << *max_element(all(dp[n])) << '\n';
    
    return 0;
}
