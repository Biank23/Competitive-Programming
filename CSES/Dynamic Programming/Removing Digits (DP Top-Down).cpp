#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 9;
const int INF = 1e9;
 
int memo[MAX_N];
 
int dp(int i) {
    if (i == 0) return 0;
    if (memo[i]) return memo[i];
    int &res = memo[i];
    res = INF;
    int num = i;
    while (num > 0) {
        int digit = num % 10;
        res = min(res, dp(i - digit) + 1);
        num /= 10;
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