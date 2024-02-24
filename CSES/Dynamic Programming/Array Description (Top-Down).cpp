#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
const int MAX_M = 102;
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
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
    bool operator!=(ModInt o) {
        return val != o.val;
    }
}; 
 
ModInt memo[MAX_N][MAX_M];
int x[MAX_N], n, m;
 
ModInt dp(int i, int j) {
    if (j < 1 || j > m) return 0;
    if (x[i] != 0 && x[i] != j) return 0;
    if (i == 0) return 1;
    ModInt &res = memo[i][j];
    if (res != -1) return res;
    res = 0;
    for (int k : {j - 1, j, j + 1}) {
        res += dp(i - 1, k);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    memset(memo, -1, sizeof memo);
    ModInt res = 0;
    for (int i = 1; i <= m; i++) {
        res += dp(n - 1, i);
    } 
    cout << res << '\n';
    
    return 0;
}