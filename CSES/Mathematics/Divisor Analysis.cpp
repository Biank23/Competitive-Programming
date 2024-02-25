#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
template<const int MOD>
struct ModInt {
    int val;
    ModInt() : val() {}
    ModInt(ll x) {
        val = int(x % MOD);
        if (val < 0) val += MOD;
    }
    ModInt& operator+=(ModInt o) {
        val += o.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    friend ModInt operator+(ModInt x, ModInt y) {
        return x += y;
    }
    ModInt& operator-=(ModInt o) {
        val -= o.val;
        if (val < 0) val += MOD;
        return *this;
    }
    friend ModInt operator-(ModInt x, ModInt y) {
        return x -= y;
    }
    ModInt& operator*=(ModInt o) {
        val = int(1LL * val * o.val % MOD);
        return *this; 
    }
    friend ModInt operator*(ModInt x, ModInt y) {
        return x *= y;
    }
    ModInt& operator^=(ll k) {
        ModInt res = 1;
        ModInt a = *this;
        while (k > 0) {
            if (k & 1) res *= a;
            a *= a, k /= 2;
        }
        return *this = res;
    }
    friend ModInt operator^(ModInt a, ll k) {
        return a ^= k;
    }
    ModInt& operator/=(ModInt o) {
        *this *= o ^ (MOD - 2);
        return *this;
    }
    friend ModInt operator/(ModInt x, ModInt y) {
        return x /= y;
    }
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
    friend istream& operator>>(istream &is, ModInt &x) {
        ll v;
        is >> v;
        x = v;
        return is;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    const int MOD = 1e9 + 7;
    ModInt<MOD> count = 1, sum = 1, prod = 1;
    ModInt<MOD - 1> count2 = 1; 
    for (int i = 0; i < n; i++) {
        ModInt<MOD> x; ll k;
        cin >> x >> k;
        count *= k + 1;
        sum *= ((x ^ (k + 1)) - 1) / (x - 1);
        prod ^= k + 1;
        prod *= (x ^ (k * (k + 1) / 2)) ^ count2.val;
        count2 *= k + 1;
    }
    cout << count << ' ' << sum << ' ' << prod << '\n';
    
    return 0;
}