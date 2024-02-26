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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s, t;
    cin >> s >> t;
    
    StringHash str(s), pattern(t);
    int n = ssize(t), cant = 0;
    for (int i = 0; i < ssize(s) - n + 1; i++) {
        if (str.getHash(i, i + n) == pattern.getHash(0, n)) {
            cant++;
        }
    }
    cout << cant << '\n';
    
    return 0;
}