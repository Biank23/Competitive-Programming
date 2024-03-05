#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto countDivisors = [](ll x) {
        int c = 0;
        for (ll i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                c += 1 + (i * i != x);
            }
        }
        return c;
    };

    auto triangular = [](int x) {
        return x * (x + 1LL) / 2LL;
    };

    const int TARGET = 500;
    int x = 1;
    while (true) {
        if (countDivisors(triangular(x)) > TARGET) {
            break;
        }
        x++;
    }
    cout << triangular(x) << '\n';

    return 0;
}