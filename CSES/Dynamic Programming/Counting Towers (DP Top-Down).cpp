#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 9;
const int MOD = 1e9 + 7;
 
using ll = long long;
 
struct ModInt {
    int val;
    ModInt(int v = 0) : val(v) {}
    ModInt& operator+=(ModInt o) {
        val += o.val;
        if (val >= MOD) {
            val -= MOD;
        }
        return *this;
    }
    ModInt& operator*=(ModInt o) {
        val = int((ll) val * o.val % MOD);
        return *this;
    }
    friend ModInt operator+(ModInt x, ModInt y) {
        return x += y;
    }
    friend ModInt operator*(ModInt x, ModInt y) {
        return x *= y;
    }
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
    bool operator!=(ModInt o) {
        return val != o.val;
    }
}; 
 
using ii = pair<ModInt, ModInt>;
#define fst first
#define snd second
 
ii memo[MAX_N];
 
ii dp(int i) {
    if (i == 0) return {1, 1};
    ii &res = memo[i];
    if (res.fst != 0) return res;
    auto [a, b] = dp(i - 1);
    res = {a * 2 + b, b * 4 + a};
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n;
        cin >> n;
        auto [a, b] = dp(n - 1);
        cout << a + b << '\n';
    }
    
    return 0;
}