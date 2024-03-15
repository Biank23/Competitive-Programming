#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> count(n + 1);
        vector<ll> pref(n + 1);
        count[0] = 0;
        pref[0] = 0LL;
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
            count[i + 1] = count[i];
            if (a[i] == 1) count[i + 1]++;
        }
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r; --l;
            ll target = pref[r] - pref[l];
            ll minSum = (r - l) + count[r] - count[l];
            if (r - l > 1 && minSum <= target) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}