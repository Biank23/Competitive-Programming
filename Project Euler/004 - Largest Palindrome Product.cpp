#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int DIGITS = 3;
    const int L = stoi("1" + string(DIGITS - 1, '0'));
    const int R = stoi(string(DIGITS, '9'));

    auto isPalindrome = [](ll x) {
        string n = to_string(x);
        string r(n.rbegin(), n.rend());
        return n == r;
    };

    ll res = 0;
    for (int x = L; x <= R; x++) {
        for (int y = L; y <= R; y++) {
            ll prod = 1LL * x * y;
            if (isPalindrome(prod)) {
                res = max(res, prod);
            }
        }
    }
    cout << res << '\n';

    return 0;
}