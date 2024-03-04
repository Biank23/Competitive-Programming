#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    vector<int> dp(n, 0), pref(n + 1, 0);
    auto initPref = [&]() {
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + dp[i];
            if (pref[i + 1] >= MOD) pref[i + 1] -= MOD;
        }
    };
    auto query = [&](int l, int r) {
        int s = pref[r] - pref[l];
        if (s < 0) s += MOD;
        return s;
    };
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        initPref();
        if(s[i - 1] == '<') {
            for (int j = 0; j <= i; j++) {
                dp[j] = query(0, j);
            }
        } else { 
            for (int j = 0; j <= i; j++) {
                dp[j]  = query(j, n);
            }
        }
    }
    initPref();
    cout << query(0, n) << '\n';
    
    return 0;
}
