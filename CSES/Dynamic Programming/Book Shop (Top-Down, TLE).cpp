#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_X = 1e5 + 9;
const int MAX_N = 1000;
const int INF = 1e9;
 
int memo[MAX_N][MAX_X], h[MAX_N], s[MAX_N];
 
int dp(int i, int j) {
    if (j < 0) return -INF;
    if (j == 0 || i < 0) return 0;
    int &res = memo[i][j];
    if (res != -1) return res;
    return res = max(dp(i - 1, j), dp(i - 1, j - h[i]) + s[i]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    memset(memo, -1, sizeof memo);
    cout << dp(n - 1, x) << '\n';
    
    return 0;
}