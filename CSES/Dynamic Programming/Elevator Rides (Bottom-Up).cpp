#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int MAX_N = 20;
 
ii dp[1<<MAX_N];
int w[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    dp[0] = {1, 0};
    for (int mask = 1; mask < 1<<n; mask++) {
        dp[mask] = {n + 1, 0};
        for (int i = 0; i < n; i++) {
            if (mask>>i&1) {
                auto [rides, last_group] = dp[mask^(1<<i)];
                last_group += w[i];
                if (last_group > x) {
                    rides++;
                    last_group = w[i];
                }
                dp[mask] = min(dp[mask], {rides, last_group});
            }
        }
    }
    auto [rides, last_group] = dp[(1<<n) - 1];
    cout << rides << '\n';
    
    return 0;
}