#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_X = 1e5 + 9;
 
bitset<MAX_X> dp;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    dp[0] = true;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        dp |= dp << x;
    }
    
    cout << dp.count() - 1 << '\n';
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}