#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 100;
    // 1^2 + 2^2 + ... + N^2 = N * (N + 1) * (2N + 1) / 6
    auto sumOfSquares = [](int n) {
        return n * (n + 1LL) * (2LL * n + 1LL) / 6LL;
    };

    // 1 + 2 + 3 + ... + N = N * (N + 1) / 2
    auto sum = [](int n) {
        return n * (n + 1LL) / 2LL;
    };

    auto square = [](ll x) {
        return x * x;
    };

    cout << square(sum(N)) - sumOfSquares(N) << '\n';

    return 0;
}