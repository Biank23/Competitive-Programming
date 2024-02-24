#include <bits/stdc++.h>
 
using namespace std;
 
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
}; 
 
ModInt dp[2][MAX_M];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    int f = 0;
    for (int i = 1; i <= m; i++) {
        dp[f][i] = (x[0] == i || x[0] == 0);
    }
    
    for (int i = 1; i < n; i++) {
        f ^= 1;
        for (int j = 1; j <= m; j++) {
            dp[f][j] = 0;
            if (x[i] == j || x[i] == 0) {
                for (int k : {j - 1, j, j + 1}) {
                    dp[f][j] += dp[f ^ 1][k];
                }
            }
        }
    }
    
    ModInt res = 0;
    for (int i = 1; i <= m; i++) {
        res += dp[f][i];
    } 
    cout << res << '\n';
    
    return 0;
}