#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
struct ModInt {
    int val;
    ModInt(int v = 0) : val(v) {}
    ModInt& operator+=(ModInt &o) {
        val += o.val;
        if (val >= MOD) {
            val -= MOD;
        }
        return *this;
    }
    friend ModInt operator+(ModInt a, ModInt b) {
        return a += b;
    }
    ModInt& operator-=(ModInt &o) {
        val -= o.val;
        if (val < 0) {
            val += MOD;
        }
        return *this;
    }
    friend ModInt operator-(ModInt a, ModInt b) {
        return a -= b;
    }
    ModInt& operator*=(ModInt &o) {
        val = int(1LL * val * o.val % MOD);
        return *this;
    }
    friend ModInt operator*(ModInt a, ModInt b) {
        return a *= b;
    }
    friend ModInt binpow(ModInt a, int k) {
        ModInt res = 1;
        while (k > 0) {
            if (k % 2 == 1) {
                res *= a;
            }
            a *= a, k /= 2;
        }
        return res;
    }
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
};
 
const int MAX_N = 1e6 + 9;
 
ModInt fact[MAX_N], inv[MAX_N];
 
void initFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
    }
    inv[MAX_N - 1] = binpow(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 1; i > 0; i--) {
        inv[i - 1] = inv[i] * i;
    }
}
 
ModInt C(int n, int k) {
    return fact[n] * inv[k] * inv[n - k];
}
 
ModInt binpow(int a, int k) {
    return binpow(ModInt(a), k);
}
 
ModInt dp[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    initFactorials();
    for (int i = 1; i <= k; i++) {
        dp[i] = binpow(i, n) * C(k, i) - dp[i - 1];
    }
    cout << dp[k] << '\n';
    
    return 0;
}