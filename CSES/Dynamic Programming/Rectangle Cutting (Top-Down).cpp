#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 501;
const int INF = 1e9;
 
int memo[MAX_N][MAX_N];
 
int dp(int a, int b) {
    if (a == b) return 0;
    int &res = memo[a][b];
    if (res != -1) return res;
    res = INF;
    for (int i = 1; i <= a / 2; i++) {
        res = min(res, dp(i, b) + dp(a - i, b) + 1);
    }
    for (int i = 1; i <= b / 2; i++) {
        res = min(res, dp(a, i) + dp(a, b - i) + 1);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    memset(memo, -1, sizeof memo);
    cout << dp(a, b) << '\n';
    
    return 0;
}