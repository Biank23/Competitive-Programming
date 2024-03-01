#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 5005;
const ll INF = 1e18;
 
ll pref[MAX_N];
pair<ll, int> dp[MAX_N][MAX_N];
 
#define fst first
#define snd second
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pref[i + 1] = pref[i] + x;
        dp[i][i] = {0, i};
    }
    
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            dp[l][r] = {INF, -1};
            int optMin = max(l, dp[l][r - 1].snd);
            int optMax = min(r - 1, dp[l + 1][r].snd);
            ll cost = pref[r + 1] - pref[l];
            for (int i = optMin; i <= optMax; i++) {
                dp[l][r] = min(dp[l][r], {dp[l][i].fst + dp[i + 1][r].fst + cost, i});
            }
        }
    }
    
    cout << dp[0][n - 1].fst << '\n';
    
    return 0;
}