#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_N = 30;

int a[MAX_N][MAX_N];
unordered_map<int, ll> memo;

inline int lsb(int i) {
    return i & (-i);
}

ll dp(int mask) {
    if (mask == 0) {
        return 0LL;
    }
    if (memo.count(mask)) {
        return memo[mask];
    }
    
    ll &ans = memo[mask];
    int i = __builtin_ctz(mask);
    for (int curr = mask ^ (1 << i); curr > 0; curr -= lsb(curr)) {
        int j = __builtin_ctz(curr);
        ans = max(ans, dp(mask ^ (1 << i) ^ (1 << j)) + a[i][j]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << dp((1<<n) - 1) << '\n';
    
    return 0;
}
