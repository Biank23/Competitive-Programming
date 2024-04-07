#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int mad(vector<int> &x) {
    int n = sz(x);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = x[i];
    }
    sort(all(a));
    auto check = [&](ll mad) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < i && a[i] - a[j] > 2 * mad) {
                j++;
            }
            if (i - j == n / 2) return a[i] - mad;
        }
        return -1LL;
    };
    ll l = -1, r = a[n-1] - a[0];
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (check(m) != -1) {
            r = m;
        } else {
            l = m;
        }
    }
    return (int) check(r);
}
