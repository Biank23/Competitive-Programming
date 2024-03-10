#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N = 5000;

    auto isPentagonal = [](ll x) {
        // n * (3 * n - 1) / 2 = x
        // n = (1 + sqrt(24 * x + 1)) / 6
        ll s = sqrt(24 * x + 1);
        return s * s == 24 * x + 1 && s % 6 == 5;
    };

    auto P = [](int n) {
        return n * (3LL * n - 1) / 2;
    };

    ll res = INF;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (isPentagonal(P(i) + P(j)) && isPentagonal(P(j) - P(i))) {
                res = min(res, P(j) - P(i));
            }
        }
    }
    cout << res << '\n';

    return 0;
}