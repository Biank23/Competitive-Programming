#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

bool isPrime(string num) {
    ll x = stoll(num);
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

ll solve(int n) {
    string num = "";
    for (int i = 1; i <= n; i++) {
        num += char('0' + i);
    }
    ll res = -1;
    do {
        if (isPrime(num)) {
            res = max(res, stoll(num));
        }
    } while (next_permutation(all(num)));
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll res = -1;
    for (int i = 9; i > 1 && res == -1; i--) {
        res = max(res, solve(i));
    }
    cout << res << '\n';

    return 0;
}