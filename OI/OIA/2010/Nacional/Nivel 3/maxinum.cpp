#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;
using ii = pair<ll, ll>;
ii operator+(ii a, ii b) {
    return {a.first + b.first, a.second + b.second};
}

ii solve(vector<int> &a) {
    int n = sz(a);
    vector<ii> dp(n + 1);
    dp[0] = {0LL, 0LL};
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + ii{0LL, a[i]};
        if (i > 0) dp[i + 1] = max(dp[i + 1], dp[i - 1] + ii{(ll) a[i - 1] * a[i], 0LL});
    }
    return dp[n];
}

int main() {
    freopen("maxinum.in", "r", stdin);
	freopen("maxinum.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v[2];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i&1].push_back(a);
    }
    
    auto [prod, sum] = solve(v[0]) + solve(v[1]);
    cout << prod << '\n';
    cout << sum << '\n';
    
    return 0;
}
