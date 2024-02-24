#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_X = 1e6 + 9;
const int MAX_N = 100;
 
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
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
    bool operator !=(ModInt o) {
        return val != o.val;
    }
}; 
 
ModInt memo[MAX_X];
int c[MAX_N], n;
 
ModInt dp(int i) {
    if (i == 0) return 1;
    if (i < 0) return 0;
    if (memo[i] != -1) return memo[i];
    ModInt &res = memo[i];
    res = 0;
    for (int j = 0; j < n; j++) {
        res += dp(i - c[j]);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    memset(memo, -1, sizeof memo);
    
    cout << dp(x) << '\n';
    
    return 0;
}