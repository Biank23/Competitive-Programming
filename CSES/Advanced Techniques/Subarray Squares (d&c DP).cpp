#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 3000;
 
ll pref[MAX_N], dp[MAX_N];
 
ll cost(int l, int r) { //(l,r]
    ll s = pref[r] - pref[l];
    return s * s;
}
ll calc(int j, int i) {
    return dp[j] + cost(j, i);
}
void solve(int l, int r, int optMin, int optMax) { //[l, r]
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
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> pref[i];
        if (i > 0) pref[i] += pref[i - 1];
        dp[i] = pref[i] * pref[i];
    }
    
    for (int i = 1; i < k; i++) {
        solve(0, n - 1, 0, n - 1);
    }
    
    cout << dp[n - 1] << '\n';
}