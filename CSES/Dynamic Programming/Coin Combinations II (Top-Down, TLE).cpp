#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_X = 1e6 + 9;
const int MAX_N = 100;
 
int memo[MAX_N][MAX_X], c[MAX_N];
 
int dp(int i, int j) {
    if (j == 0) return 1;
    if (j < 0 || i < 0) return 0;
    int &res = memo[i][j];
    if (res != -1) return res;
    res = dp(i - 1, j) + dp(i, j - c[i]);
    if (res >= MOD) res -= MOD;
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    memset(memo, -1, sizeof memo);
    cout << dp(n - 1, x) << '\n';
    
    return 0;
}
