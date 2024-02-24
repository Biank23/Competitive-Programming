#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 100;
const int MAX_X = 1e6 + 9;
const int INF = 1e9;
 
int memo[MAX_X], c[MAX_N], n;
 
int dp(int i) {
    if (i == 0) return 0;
    if (i < 0) return INF;
    if (memo[i] != -1) return memo[i];
    int &res = memo[i];
    res = INF;
    for (int j = 0; j < n; j++) {
        res = min(res, dp(i - c[j]) + 1);
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
    
    int res = dp(x);
    if (res == INF) res = -1;
    cout << res << '\n';
    
    return 0;
}