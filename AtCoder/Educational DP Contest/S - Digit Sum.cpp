#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int MOD = 1e9+7;
const int CANT_DIGITS = 1e4+9;
const int MAX_D = 100;

int dp[CANT_DIGITS][MAX_D][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string k;
    int d;
    cin >> k >> d;
    int n = sz(k);
    dp[n][0][0] = dp[n][0][1] = 1;
    for (int digit = n - 1; digit >= 0; digit--) {
        for (int sum = 0; sum < d; sum++) {
            for (bool tight : {false, true}) {
                int &curr = dp[digit][sum][tight];
                int maxi = tight ? k[digit] - '0' : 9;
                for (int i = 0; i <= maxi; i++) {
                    curr += dp[digit+1][(sum + i) % d][tight && i == maxi];
                    if (curr >= MOD) curr -= MOD;
                }

            }
        }
    }

    int res = dp[0][0][true];
    if (!res) res = MOD - 1;
    else res--;
    cout << res << '\n';
    
    return 0;
}
