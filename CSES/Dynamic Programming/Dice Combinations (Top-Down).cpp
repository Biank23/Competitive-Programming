#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 9;
 
int memo[MAX_N]; 
 
int dp(int i) {
    if (i == 0) return 1;
    if (memo[i]) return memo[i];
    
    int &res = memo[i];
    for (int j = 1; j <= min(6, i); j++) {
        res += dp(i - j);
        if (res >= MOD) {
            res -= MOD;
        }
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    cout << dp(n) << '\n';
    
    return 0;
}