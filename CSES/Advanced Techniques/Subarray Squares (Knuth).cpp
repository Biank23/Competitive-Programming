#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 3003;
 
ll pref[MAX_N], dp[MAX_N][MAX_N];
int opt[MAX_N][MAX_N];
 
ll cost(int l, int r) { //(l,r]
    ll s = pref[r] - pref[l];
    return s * s;
}
ll calc(int j, int i, int k) {
    return dp[k - 1][j] + cost(j, i);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, d;
    cin >> n >> d;
    
    for (int i = 0; i < n; i++) {
        cin >> pref[i];
        if (i > 0) pref[i] += pref[i - 1];
        dp[0][i] = pref[i] * pref[i];
        opt[0][i] = 0;
    }
    
    for (int i = 1; i < d; i++) {
        opt[i][n] = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            int optMin = opt[i - 1][j];
            int optMax = opt[i][j + 1];
            opt[i][j] = optMin;
            for (int k = optMin + 1; k <= min(optMax, j); k++) {
                if (calc(k, j, i) < calc(opt[i][j], j, i)) opt[i][j] = k;
            }
            dp[i][j] = calc(opt[i][j], j, i);
        }
    }
    
    cout << dp[d - 1][n - 1] << '\n';
}