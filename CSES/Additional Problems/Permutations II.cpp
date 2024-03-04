#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
struct ModInt {
    int val;
    ModInt(int v = 0) : val(v) {}
    ModInt& operator+=(ModInt o) {
        val += o.val;
        if (val >= MOD) {
            val -= MOD;
        }
        return *this;
    }
    friend ModInt operator+(ModInt a, ModInt b) {
        return a += b;
    }
    ModInt& operator*=(ModInt &o) {
        val = int(1LL * val * o.val % MOD);
        return *this;
    }
    friend ModInt operator*(ModInt a, ModInt b) {
        return a *= b;
    }
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
};
 
const int MAX_N = 1001;
 
ModInt dp[MAX_N][MAX_N][3];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][0] += dp[i - 1][j + 1][k] * j * (j + 1 - k);
                dp[i][j][1] += dp[i - 1][j][k] * (2 * j - k);
                dp[i][j][2] += dp[i - 1][j - 1][k];
            }
        }
    }
    
    ModInt res = 0;
    for (int k = 0; k < 3; k++) {
        res += dp[n][1][k];
    }
    cout << res << '\n';
    
    return 0;
}