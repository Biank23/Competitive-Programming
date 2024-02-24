#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
 
const int MAX_N = 20;
 
ii memo[1<<MAX_N];
int w[MAX_N], n, x;
 
ii dp(int mask) {
    if (mask == 0) return {1, 0};
    if (memo[mask] != ii{-1, -1}) return memo[mask];
    ii &res = memo[mask];
    res = {n + 1, 0};
    for (int i = 0; i < n; i++) {
        if (mask>>i&1) {
            auto [rides, last_group] = dp(mask^(1<<i));
            last_group += w[i];
            if (last_group > x) {
                rides++;
                last_group = w[i];
            }
            res = min(res, {rides, last_group});
        }
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    memset(memo, -1, sizeof memo);
    auto [rides, last_group] = dp((1<<n) - 1);
    cout << rides << '\n';
    
    return 0;
}