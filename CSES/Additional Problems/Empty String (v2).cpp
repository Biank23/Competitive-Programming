#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
 
const uint MOD = 1e9+7;
const uint DMOD = 2e9+14;
const uint R = -2068349879;
const uint N2 = 582344008;
 
struct ModInt {
    uint v;
 
    static constexpr uint reduce(const ull &x) {
        return (x + ull(uint(x) * R) * MOD) >> 32;
    }
    constexpr ModInt() : v(MOD) {}
    constexpr ModInt(int) : v(294967268) {}
    constexpr ModInt &operator+=(const ModInt &b) {
        v += b.v;
        if (v >= DMOD) v -= DMOD;
        return *this;
    }
    constexpr ModInt operator+(const ModInt &b) const { return ModInt(*this) += b; }
    constexpr ModInt &operator*=(const ModInt &b) {
        v = reduce(ull(v) * b.v);
        return *this;
    }
    constexpr ModInt operator*(const ModInt &b) const { return ModInt(*this) *= b; }
    
    constexpr uint get() const {
        uint ans = reduce(v);
        if (ans >= MOD) ans -= MOD;
        return ans;
    }
    
    friend ostream &operator<<(ostream &os, const ModInt &b) {
        return os << b.get();
    }
};
 
ModInt dp[500][500], C[251][251];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int SZ = ssize(s);
    
    int M = SZ/2;
    for (int n = 0; n <= M; n++) {
        C[0][n] = 1;
    }
    for (int k = 1; k <= M; k++) {
        C[k][k] = 1;
        for (int n = k + 1; n <= M; n++) {
            C[k][n] = C[k][n-1] + C[k-1][n-1];
        }
    }
    
    for (int i = 0; i < SZ; i++) {
        dp[i+1][i] = 1;
    }
    
    for (int l = SZ - 1; l >= 0; l--) {
        for (int m = l + 1, k = 1; m < SZ; m += 2, k++) {
            if (s[l] != s[m]) continue;
            dp[l][m] += dp[l+1][m-1];
            for (int r = m + 2, n = k + 1; r < SZ; r += 2, n++) {
                dp[l][r] += dp[l+1][m-1] * dp[m+1][r] * C[k][n];
            }
        }
    }
    
    cout << dp[0][SZ-1] << '\n';
    
    return 0;
}