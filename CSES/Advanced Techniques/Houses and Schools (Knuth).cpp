#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 3001;
const ll INF = 1e18;
 
ll pref[MAX_N], acumL[MAX_N], acumR[MAX_N];
ll x[MAX_N], dp[MAX_N][MAX_N];
int opt[MAX_N][MAX_N], n;
 
ll moveLeft(int i, int j) {
    return acumL[j] - acumL[i] - (pref[j + 1] - pref[i + 1]) * i;
}
ll moveRight(int i, int j) {
    return acumR[j] - acumR[i] - (pref[j] - pref[i]) * (n - j);
}
ll calc(int l, int r, int i) {
    int m = (l + r) / 2;
    return dp[i - 1][l] + moveLeft(l, m) + moveRight(m + 1, r);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int d;
    cin >> n >> d;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        pref[i + 1] = pref[i] + x[i];
    }
    for (int i = 0; i < n - 1; i++) {
        acumL[i+1] = acumL[i] + x[i + 1] * (i + 1); 
        acumR[i+1] = acumR[i] + x[i] * (n - i);
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = moveRight(0, i);
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
    
    ll res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[d - 1][i] + moveLeft(i, n - 1));
    }
    cout << res << '\n';
    
    return 0;
}