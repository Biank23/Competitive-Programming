#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9+9; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int B1 = uniform_int_distribution<int>(0, MOD - 1)(rng);
const int B2 = uniform_int_distribution<int>(0, MOD - 1)(rng);
 
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
    int B;
    vector<ModInt> powB, hash;
    StringHash(string s, int b) : B(b), powB(ssize(s) + 1), hash(ssize(s) + 1) {
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
 
#define all(x) begin(x), end(x)
 
using ii = pair<int, int>;
#define fst first
#define snd second
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int n = ssize(s);
    StringHash str1(s, B1), str2(s, B2);
    
    auto getHash = [&](int l, int r) {
        return ii{str1.getHash(l, r), str2.getHash(l, r)};
    };
    
    auto check = [&](int k) {
        vector<pair<ii, int>> v;
        for (int i = 0; i <= n - k; i++) {
            v.emplace_back(getHash(i, i + k), i);
        }
        sort(all(v));
        for (int i = 0; i < n - k; i++) {
            if (v[i].fst == v[i + 1].fst) {
                return s.substr(v[i].snd, k);
            }
        }
        return "-"s;
    };
    
    int l = 0, r = n;
    string res = "-1";
    while (r - l > 1) {
        int m = (l + r) / 2;
        string c = check(m);
        if (c != "-") {
            l = m, res = c;
        } else {
            r = m;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}