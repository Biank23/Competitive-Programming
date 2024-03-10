#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int TARGET = 200; //pences
    const vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};

    vector<int> dp(TARGET + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < sz(coins); i++) {
        for (int j = coins[i]; j <= TARGET; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    cout << dp[TARGET] << '\n';

    return 0;
}