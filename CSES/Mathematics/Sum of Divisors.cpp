#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MOD = 1e9 + 7, INV_2 = 5e8 + 4;
 
struct ModInt {
    int val;
    ModInt(ll x) {
        val = x % MOD;
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
        val = 1LL * val * o.val % MOD;
        return *this; 
    }
    friend ModInt operator*(ModInt x, ModInt y) {
        return x *= y;
    }
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
};
 
ModInt sum(ModInt l, ModInt r) {
    return (l + r) * (r - l + 1) * INV_2;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll N;
	cin >> N;
	
	ModInt res = 0;
	for (ll l = 1, r; l <= N; l = r + 1) {
        ll divisors = N / l;
		r = N / divisors;
        res += divisors * sum(l, r);
	}
	
	cout << res << '\n';
	
	return 0;
}