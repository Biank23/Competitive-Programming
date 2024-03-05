#include <bits/stdc++.h>

using namespace std;

using ll = long long;

unordered_map<ll, int> c{{1,1}};

int collatz(ll x) {
    if (!c.count(x)) {
        if (x % 2 == 0) {
            c[x] = collatz(x / 2) + 1;
        } else {
            c[x] = collatz(3 * x + 1) + 1;
        }
    }
    return c[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1e6;
    pair<int, int> res = {-1, 0};
    for (int i = 2; i <= N; i++) {
        res = max(res, {collatz(i), i});
    }
    cout << res.second << '\n';

    return 0;
}