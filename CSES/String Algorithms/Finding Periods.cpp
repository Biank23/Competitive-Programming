#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9+9; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int B = uniform_int_distribution<int>(0, MOD - 1)(rng);
 
struct ModInt {
    int val;
    ModInt(int v = 0) : val(v) {}
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
};
 
struct StringHash {
    vector<ModInt> powB, hash;
    StringHash(string s) : powB(ssize(s) + 1), hash(ssize(s) + 1) {
        powB[0] = 1, hash[0] = 0;
        for (int i = 0; i < ssize(s); i++) {
            powB[i + 1] = powB[i] * B;
            hash[i + 1] = hash[i] * B + s[i];
        }
    }
    int getHash(int l, int r) { //[l, r)
        return (hash[r] - hash[l] * powB[r - l]).val;
    }
};
 
bool check(StringHash &s, int r, int n) {
    for (int i = 0; i < n; i += r) {
        int sz = min(r, n - i);
        if (s.getHash(0, sz) != s.getHash(i, i + sz)) {
            return false;
        }
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int n = ssize(s);
    StringHash str(s);
    for (int i = 1; i <= ssize(s); i++) {
        if (check(str, i, n)) {
            cout << i << ' ';
        }
    }
    
    return 0;
}