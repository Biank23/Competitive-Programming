#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 10;
const int MAX_M = 1000;
const int MOD = 1e9 + 7;
 
int memo[MAX_M][MAX_N][1<<MAX_N], n, m;
 
int dp(int j, int i, int mask) {
    if (j == -1) return mask == 0;
    int &res = memo[j][i][mask];
    if (res != -1) return res;
    int prevI = i - 1, prevJ = j;
    if (prevI == -1) prevI = n - 1, prevJ--;
    res = dp(prevJ, prevI, mask ^ (1<<i));
    if (i != 0 && !(mask>>i&1) && !(mask>>(i-1)&1)) {
        res += dp(prevJ, prevI, mask ^ (1<<(i-1)));
        if (res >= MOD) {
            res -= MOD;
        }
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    memset(memo, -1, sizeof memo);
    cout << dp(m - 1, n - 1, 0) << '\n';
    
    return 0;
}