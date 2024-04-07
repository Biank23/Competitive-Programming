#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

ll bombones(int K, vi &x) {
    ll tot = accumulate(all(x), 0LL);
    ll l = 0, r = tot + 1;
    auto check = [&](ll c) {
        ll sum = 0, cant = 0;
        for (int i = 0; i < sz(x); i++) {
            if (x[i] > c) cant++;
            else sum += x[i];
        }
        cant += sum / c;
        return cant >= K;
    };
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
