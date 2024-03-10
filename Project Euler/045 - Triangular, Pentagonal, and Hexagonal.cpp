#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto isTriangular = [](ll x) {
        // n * (n + 1) / 2 = x
        // n = (sqrt(8 * x + 1) - 1) / 2
        ll s = sqrt(8 * x + 1);
        return s * s == 8 * x + 1;
    };

    auto isPentagonal = [](ll x) {
        // n * (3 * n - 1) / 2 = x
        // n = (1 + sqrt(24 * x + 1)) / 6
        ll s = sqrt(24 * x + 1);
        return s * s == 24 * x + 1 && s % 6 == 5;
    };

    auto H = [](int n) {
        return n * (2LL * n - 1);
    };

    //It's given T_285 = P_165 = H_143 = 40755
    int n = 144;
    while (!isTriangular(H(n)) || !isPentagonal(H(n))) {
        n++;
    }

    cout << H(n) << '\n';

    return 0;
}