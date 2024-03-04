#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
const int MOD = 1e9 + 7;
 
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
    friend ModInt operator+(ModInt a, ModInt b) {
        return a += b;
    }
    ModInt& operator*=(ModInt &o) {
        val = int(1LL * val * o.val % MOD);
        return *this;
    }
    friend ModInt operator*(ModInt a, ModInt b) {
        return a *= b;
    }
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
};
 
const int MAX_N = 101;
const int MAX_T = MAX_N;
const int MAX_K = MAX_N * MAX_T;
 
ModInt dp[2][MAX_N][MAX_K];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(all(t), greater<int>());
    
    int f = 0, sum = 0;
    dp[f][0][0] = 1;
    for (int i = 0; i < n; i++) {
        f ^= 1, sum += t[i];
        for (int j = 0; j <= n - i; j++) {
            for (int k = 0; k <= sum; k++) {
                dp[f][j][k] = dp[f ^ 1][j][k] * (j + 1);
                if (j > 0 && k >= t[i]) {
                    dp[f][j][k] += dp[f ^ 1][j - 1][k - t[i]];
                }
                if (j < n - i && k + t[i] <= sum) {
                    dp[f][j][k] += dp[f ^ 1][j + 1][k + t[i]] * (j + 1);
                }
            }
        }
    }
    
    ModInt res = 0;
    for (int k = 0; k <= x; k++) {
        res += dp[f][0][k];
    }
    cout << res << '\n';
    
    return 0;
}