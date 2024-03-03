#include <bits/stdc++.h>

using namespace std;
 
template<int MOD>
struct ModInt {
    int v;
    ModInt() : v(0) {}
    ModInt(int x) : v(x) {}
    ModInt& operator+=(const ModInt &o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    friend ModInt operator+(ModInt x, const ModInt v) {
        return x += v;
    }
    ModInt& operator*=(const ModInt &o) {
        v = int((long long) v * o.v % MOD);
        return *this;
    }
    friend ModInt operator*(ModInt x, const ModInt v) {
        return x *= v;
    }
    friend ostream& operator<<(ostream &os, const ModInt &x) {
        return os << x.v;
    }
};
 
ModInt<int(1e9+7)> dp[500][500], C[300][300];
 
void init_choose(int SZ) {
    for (int i = 0; i < SZ; i++) {
        C[i][0] = C[i][i] = 1;
    }
    for (int n = 1; n < SZ; n++) {
        for (int k = 1; k < n; k++) {
            C[n][k] = C[n-1][k] + C[n-1][k-1];
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int n = ssize(s);
    
    init_choose(n/2+1);
    
    for (int i = 0; i < n; i++) {
        dp[i+1][i] = 1;
    }
    
    auto compute = [&](int l, int r) {
        for (int m = l + 1; m <= r; m += 2) {
            if (s[l] != s[m]) continue;
            dp[l][r] += dp[l+1][m-1] * dp[m+1][r] * C[(r-l+1)/2][(m-l+1)/2];
        }
    };
    
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r += 2) {
            compute(l,r);
        }
    }
    
    cout << dp[0][n-1] << '\n';
    
    return 0;
}