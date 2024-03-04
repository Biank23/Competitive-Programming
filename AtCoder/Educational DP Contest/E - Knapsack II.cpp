#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

const ll INF = 1e14+10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    
    ll y = accumulate(all(v), 0LL) + 1;
    vector<ll> dp(y + 1,INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = y; j >= 0; j--) {
            dp[j] = min(dp[j], dp[max(0, j - v[i])] + w[i]);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= y; i++) {
        if (dp[i] <= x) ans = i;
    }
    
    cout << ans << '\n';
    
    return 0;
}
