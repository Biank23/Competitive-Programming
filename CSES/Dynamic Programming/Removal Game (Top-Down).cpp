#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 5005;
 
ll memo[MAX_N][MAX_N], x[MAX_N];
 
ll dp(int l, int r) {
    if (l > r) return 0;
    ll &res = memo[l][r];
    if (res != -1) return res;
    return res = max(x[l] - dp(l + 1, r),
                     x[r] - dp(l, r - 1));
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        tot += x[i];
    }
    memset(memo, -1, sizeof memo);
    // first + second = tot
    // first - second = dp(0, n - 1)
    // first = (tot + dp(0, n - 1)) / 2
    cout  << (tot + dp(0, n - 1)) / 2 << '\n';
    
    return 0;
}