#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_DIGITS = 19;
const int BASE = 10;
 
using ll = long long;
 
ll memo[MAX_DIGITS][BASE][2][2];
string num;
 
ll dp(int i, int lastDigit, bool leadingZero, bool tight) {
    if (i == ssize(num)) {
        return 1;
    }
    
    ll &res = memo[i][lastDigit][leadingZero][tight];
    if (res != -1) {
        return res;
    }
    
    int l = 0, r = 9;
    if (tight) {
        r = num[i] - '0';
    }
    
    res = 0;
    for (int digit = l; digit <= r; digit++) {
        if (digit != lastDigit || leadingZero) {
            res += dp(i + 1, digit, leadingZero && digit == 0, tight && digit == r);
        }
    }
    return res;
}
 
ll solve(ll x) {
    if (x == -1) return 0;
    num = to_string(x);
    memset(memo, -1, sizeof memo);
    return dp(0, 0, true, true);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << '\n';
    
    return 0;
}
