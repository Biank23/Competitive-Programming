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
    ModInt& operator-=(ModInt o) {
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
 
#define all(x) begin(x), end(x)
 
const int MAX_N = 2e6 + 9;
 
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
 
ModInt paths(int h, int w) {
    int n = h + w - 2, k = w - 1;
    return fact[n] * inv[k] * inv[n - k];
}
 
ModInt dp[MAX_N];
 
using ii = pair<int, int>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<ii> trap(m);
    for (auto &[x, y] : trap) {
        cin >> x >> y;
    }
    sort(all(trap));
    trap.emplace_back(n, n);
    
    initFactorials();
    for (int i = 0; i <= m; i++) {
        auto [h, w] = trap[i];
        dp[i] = paths(h, w);
        for (int j = 0; j < i; j++) {
            auto [x, y] = trap[j];
            if (x <= h && y <= w) {
                dp[i] -= dp[j] * paths(h - x + 1, w - y + 1);
            }
        }
    }
    cout << dp[m] << '\n';
    
    return 0;
}