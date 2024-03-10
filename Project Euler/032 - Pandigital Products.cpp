#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto digits = [](int num) {
        return (int)floor(log10(num)) + 1;
    };

    auto getMask = [](ll num) {
        int mask = 0;
        while (num > 0) {
            int digit = num % 10;
            mask |= (1 << digit);
            num /= 10;
        }
        return mask;
    };

    const int TARGET = getMask(123456789);

    set<ll> s;
    ll res = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a; b < 10000; b++) {
            ll prod = a * b;
            if (digits(a) + digits(b) + digits(prod) > 9) break;
            if ((getMask(a) | getMask(b) | getMask(prod)) == TARGET && s.find(prod) == end(s)) {
                res += prod;
                s.insert(prod);
            }
        }
    }
    cout << res << '\n';

    return 0;
}