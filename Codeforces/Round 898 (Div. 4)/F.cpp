#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), h(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        
        int ans = 0;
        int l = 0;
        ll sum = 0;
        for (int r = 0; r < n; r++) {
            sum += a[r];
            if (r != 0 && h[r - 1] % h[r] != 0) {
                l = r, sum = a[r];
            }
            while (sum > k) {
                sum -= a[l++];
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
    
    return 0;
}
