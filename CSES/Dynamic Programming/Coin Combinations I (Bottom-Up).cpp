#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_X = 1e6 + 9;
const int MAX_N = 100;
 
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
    friend ostream& operator<<(ostream &os, ModInt &x) {
        return os << x.val;
    }
}; 
 
ModInt dp[MAX_X];
int c[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0) dp[i] += dp[i - c[j]];
        }
    }
    
    cout << dp[x] << '\n';
    
    return 0;
}
SHARE