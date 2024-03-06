#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 3001;
const ll INF = 1e18;
 
ll pref[MAX_N], acumL[MAX_N], acumR[MAX_N];
ll x[MAX_N], dp[MAX_N];
int n;
 
ll moveLeft(int i, int j) {
    return acumL[j] - acumL[i] - (pref[j + 1] - pref[i + 1]) * i;
}
ll moveRight(int i, int j) {
    return acumR[j] - acumR[i] - (pref[j] - pref[i]) * (n - j);
}
ll calc(int l, int r) {
    int m = (l + r) / 2;
    return dp[l] + moveLeft(l, m) + moveRight(m + 1, r);
}
 
void solve(int l, int r, int optMin, int optMax) {
    if (l > r) return;
    int i = (l + r) / 2;
    int opt = optMin;
    for (int j = optMin + 1; j <= min(optMax, i); j++) {
        if (calc(j, i) < calc(opt, i)) opt = j;
    }
    ll newDP = calc(opt, i);
    solve(i + 1, r, opt, optMax);
    solve(l, i - 1, optMin, opt);
    dp[i] = newDP;
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        pref[i + 1] = pref[i] + x[i];
    }
    for (int i = 1; i < n; i++) {
        acumL[i] = acumL[i - 1] + x[i] * i; 
    }
    for (int i = 0; i < n - 1; i++) {
        acumR[i + 1] = acumR[i] + x[i] * (n - i);
    }
    for (int i = 0; i < n; i++) {
        dp[i] = moveRight(0, i);
    }
    
    for (int i = 1; i < k; i++) {
        solve(0, n - 1, 0, n - 1);
    }
    
    ll res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[i] + moveLeft(i, n - 1));
    }
    cout << res << '\n';
    
    return 0;
}