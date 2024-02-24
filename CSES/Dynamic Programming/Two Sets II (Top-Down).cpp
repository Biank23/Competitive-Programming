#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 500;
const int MAX_SUM = MAX_N * (MAX_N + 1) / 2;
const int MAX_TARGET =  MAX_SUM / 2 + 1;
const int MOD = 1e9 + 7; 
 
int memo[MAX_N][MAX_SUM];
 
int dp(int i, int j) {
    if (j == 0) return 1;
    if (j < 0 || i <= 0) return 0;
    int &res = memo[i][j];
    if (res != -1) return res;
    res = dp(i - 1, j) + dp(i - 1, j - i);
    if (res >= MOD) {
        res -= MOD;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << "0\n";
        return 0;
    }
    memset(memo, -1, sizeof memo);
    cout << dp(n - 1, sum / 2) << '\n';
    
    return 0;
}