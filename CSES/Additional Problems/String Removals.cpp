#include <bits/stdc++.h>
 
using namespace std;
 
const int ALPHA = 26;
const int MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    
    int n = ssize(s);
    vector<int> dp(n + 1, 0), //prefix
                last(ALPHA, 0);
                
    auto query = [&](int l, int r) { //[l, r]
        int res = dp[r];
        if (l > 0) {
            res -= dp[l - 1];
            if (res < 0) res += MOD;
        }
        return res;
    };
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int &j = last[s[i - 1] - 'a'];
        dp[i] = dp[i - 1] + query(j, i - 1);
        if (dp[i] >= MOD) dp[i] -= MOD;
        j = i;
    }
    cout << query(1, n) << '\n';
    
    return 0;
}
