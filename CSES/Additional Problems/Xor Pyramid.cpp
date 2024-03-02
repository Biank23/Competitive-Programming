#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<int> a(n), f(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) f[i] = f[i - 1] + __builtin_ctz(i);
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (f[n - 1] - f[i] - f[n - 1 - i] == 0) {
            res ^= a[i];
        }
    }
    cout << res << '\n';
    
    return 0;
}