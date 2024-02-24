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
}; 
 
using ii = pair<ModInt, ModInt>;
#define fst first
#define snd second
 
ii dp[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    dp[0] = {1, 1};
    for (int i = 1; i < MAX_N; i++) {
        dp[i].fst = dp[i - 1].fst * 2 + dp[i - 1].snd;
        dp[i].snd = dp[i - 1].snd * 4 + dp[i - 1].fst;
    }
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n;
        cin >> n;
        --n;
        cout << dp[n].fst + dp[n].snd << '\n';
    }
    
    return 0;
}