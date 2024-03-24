#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        n *= 2;
        vector<ll> a(n);
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tot ^= a[i];
        }
        int j = -1;
        for (int i = 0; i < n; i++) {
            if ((tot ^ a[i]) >= k) j = i;
        }
        int ans = 2;
        if (tot >= k) {
            ans = 1, j = -1;
        }
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            int p = (i == j) + 1;
            cout << p << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
