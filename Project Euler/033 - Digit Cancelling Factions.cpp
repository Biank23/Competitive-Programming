#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto check = [](int x, int y){
        // ba / ca = b / c
        // (10 * b + a) / (10 * c + a) = b / c
        // (10 * b + a) * c = (10 * c + a) * b
        // 10 * b * c + a * c = 10 * b * c + a * b
        // a * c = a * b
        // a * (c - b) = 0
        // a = 0 (trivial case) or c = b (imposible because x < y)

        // ab / ac = b / c
        // (10 * a + b) / (10 * a + c) = b / c
        // (10 * a + b) * c = (10 * a + c) * b
        // 10 * a * c + b * c = 10 * a * b + b * c
        // 10 * a * c = 10 * a * b
        // c = b (imposible because x < y)

        // ab / ca = b / c
        // x / y == (x % 10) / (y / 10)
        if ((x / 10) == (y % 10) && x * (y / 10) == (x % 10) * y) {
            return true;
        }

        // ba / ac = b / c
        // x / y == (x / 10) / (y % 10)
        if ((x % 10) == (y / 10) && x * (y % 10) == (x / 10) * y) {
            return true;
        }

        return false;
    };

    ll num = 1, den = 1;
    for (int a = 10; a < 100; a++) {
        // a / b < 1 => a < b
        for (int b = a + 1; b < 100; b++) {
            if (check(a, b)) {
                num *= a, den *= b;
                int commonDivisor = gcd(num, den);
                num /= commonDivisor, den /= commonDivisor;
            }
        }
    }
    cout << den << '\n';

    return 0;
}