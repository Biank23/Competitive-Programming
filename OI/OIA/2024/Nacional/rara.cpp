#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

ll cant(ll V) {
    vector<int> monedas = {100, 50, 25, 10, 5, 2, 1};
    ll res = 0LL;
    for (int x : monedas) {
        res += V / x, V %= x;
    }
    return res;
}

ll rara(ll V, ll X) {
    ll res = V;
    #define probar(k) res = min(res, k + cant(V - X * k))
    if (X <= 100) for (ll k = 0; k < 100 && V - X * k >= 0; k++) probar(k);
    else for (ll k = V / X; k > V / X - 100 && k >= 0; k--) probar(k);
    return res;
}
