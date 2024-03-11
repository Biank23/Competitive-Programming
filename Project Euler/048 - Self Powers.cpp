#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
const ll MOD = 1e10;

ll mul(ll a, ll b) {
    return (__int128) a * b % MOD;
}

ll binpow(ll a, ll k) {
    ll res = 1;
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1000;
    ll res = 0;
    for (int i = 1; i <= N; i++) {
        res += binpow(i, i);
        if (res >= MOD) res -= MOD;
    }
    cout << res << '\n';

    return 0;
}