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
    friend ModInt operator+(ModInt x, ModInt y) {
        return x += y;
    }
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
    bool operator!=(ModInt o) {
        return val != o.val;
    }
}; 
 
string grid[MAX_N];
ModInt memo[MAX_N][MAX_N];
int n;
 
bool valid_position(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}
 
ModInt dp(int i, int j) {
    if (!valid_position(i, j) || grid[i][j]=='*') {
        return 0;
    }
    if (i == 0 && j == 0) {
        return 1;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    return memo[i][j] = dp(i - 1, j) + dp(i, j - 1);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    memset(memo, -1, sizeof memo);
    
    cout << dp(n - 1, n - 1) << '\n'; 
    
    return 0;
}