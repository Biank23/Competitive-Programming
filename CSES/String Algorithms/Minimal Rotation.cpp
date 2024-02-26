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
    
    string s;
    cin >> s;
    int n = ssize(s);
    s += s;
    StringHash str(s);
    
    auto getMin = [&](int i, int j) {
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (str.getHash(i, i + m) == str.getHash(j, j + m)) {
                l = m;
            } else {
                r = m;
            }
        }
        if (s[i + l] < s[j + l]) {
            return i;
        } else {
            return j;
        }
    };
    
    int minimal = 0;
    for (int i = 1; i < n; i++) {
        minimal = getMin(minimal, i);
    }
    cout << s.substr(minimal, n) << '\n';
    
    return 0;
}