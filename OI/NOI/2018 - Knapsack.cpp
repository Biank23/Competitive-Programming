#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ii = pair<ll, ll>;
 
#define all(x) begin(x), end(x)
#define sz(x) int(x.size())
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int s, n;
    cin >> s >> n;
    vector<ii> items[s + 1];
    for (int i = 0; i < n; i++) {
        ll v, w, k;
        cin >> v >> w >> k;
        items[w].emplace_back(v, k);
    }
    vector<ll> dp(s + 1, 0);
    for (int w = 1; w <= s; w++) {
        sort(all(items[w]), greater<ii>());
        int i = 0;
        for (ll cant = 1; cant * w <= s && i < sz(items[w]); cant++) {
            auto &[v, k] = items[w][i];
            for (int j = s; j >= w; j--) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
            if (--k == 0) i++;
        }
    }
    cout << dp[s] << '\n';
    
    return 0;
}