#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_DIGITS = 20;
const int BASE = 10;
 
using ll = long long;
 
ll dp[MAX_DIGITS][BASE][2][2];
 
ll solve(ll x) {
    if (x == -1) return 0;
    string num = to_string(x);
    int n = ssize(num);
    memset(dp, 0, sizeof dp);
    for (int i = n; i >= 0; i--) {
        for (int lastDigit = 0; lastDigit < BASE; lastDigit++) {
            for (bool leadingZero : {false, true}) {
                for (bool tight : {false, true}) {
                    ll &res = dp[i][lastDigit][leadingZero][tight];
                    if (i == n) {
                        res = 1;
                        continue;
                    }
                    res = 0;
                    int l = 0, r = 9;
                    if (tight) {
                        r = num[i] - '0';
                    }
                    for (int digit = l; digit <= r; digit++) {
                        if (digit != lastDigit || leadingZero) {
                            res += dp[i + 1][digit][leadingZero && digit == 0][tight && digit == r];
                        }
                    }
                }
            }
        }
    }
    return dp[0][0][true][true];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << '\n';
    
    return 0;
}