#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_N = 1000;
 
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
 
string grid[MAX_N];
ModInt dp[MAX_N][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    dp[0][0] = (grid[0][0] == '.');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                if (i != 0) dp[i][j] += dp[i - 1][j];
                if (j != 0) dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << dp[n - 1][n - 1] << '\n'; 
    
    return 0;
}