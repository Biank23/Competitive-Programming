#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int countOnes(int a, int b) {
    int c = 0;
    while (a > 0) {
        if (a % b == 1) c++;
        a /= b;
    }
    return c;
}
 
const int MAX_N = 20;
 
int a[MAX_N], c[MAX_N][MAX_N];
ll dp[MAX_N][1 << MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            c[i][j] = countOnes(a[i], 2) == countOnes(a[j], 2) ||
                      countOnes(a[i], 3) == countOnes(a[j], 3);
        }
    }
    for (int mask = 1; mask < 1 << n; mask++) {
        if (__builtin_popcount(mask) < 2) {
            int i = __builtin_ctz(mask);
            dp[i][mask] = 1;
            continue;
        }
        for (int x = mask; x > 0; x -= x&-x) {
            int i = __builtin_ctz(x);
            for (int y = x ^ (1 << i); y > 0; y -= y&-y) {
                int j = __builtin_ctz(y);
                if (c[i][j]) {
                    dp[i][mask] += dp[j][mask ^ (1 << i)];
                    dp[j][mask] += dp[i][mask ^ (1 << j)];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i][(1 << n) - 1];
    }
    cout << ans << '\n';
    
    
    return 0;
}