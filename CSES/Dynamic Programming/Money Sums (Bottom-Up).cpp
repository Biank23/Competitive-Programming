#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_X = 1e5 + 9;
 
bool dp[MAX_X];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    dp[0] = true;
    int sum = 0, res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        for (int j = sum; j >= x; j--) {
            if (!dp[j] && dp[j - x]) {
                res++;
                dp[j] = true;
            }
        }
    }
    
    cout << res << '\n';
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}