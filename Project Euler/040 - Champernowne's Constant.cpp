#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int getDigit(ll k) {
    int digits = 1;
    ll cant = 9;
    ll powerOf10 = 1;
    while (digits * cant < k) {
        k -= digits * cant;
        cant *= 10;
        powerOf10 *= 10;
        digits++;
    }
    ll number = powerOf10 + (k - 1) / digits;
    int digit = to_string(number)[(k - 1) % digits] - '0';
    return digit;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll ans = 1, pos = 1;
    for (int i = 0 ; i < 7; i++) {
        ans *= getDigit(pos);
        pos *= 10;
    }
    cout << ans << '\n';

    return 0;
}