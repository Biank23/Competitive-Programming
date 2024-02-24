#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 5005;
const int INF = 1e9;
 
int memo[MAX_N][MAX_N];
string a, b;
 
int dp(int i, int j) {
    if (i == 0 && j == 0) return 0;
    if (i < 0 || j < 0) return INF;
    int &res = memo[i][j];
    if (res != -1) return res;
    res = min(dp(i - 1, j), dp(i, j - 1)) + 1;
    if (i != 0 && j != 0) {
        int cost = (a[i - 1] != b[j - 1]);
        res = min(res, dp(i - 1, j - 1) + cost);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> a >> b;
    int n = ssize(a);
    int m = ssize(b);
    memset(memo, -1, sizeof memo);
    cout << dp(n, m) << '\n';
    
    return 0;
}