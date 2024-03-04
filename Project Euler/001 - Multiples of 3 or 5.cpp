#include <bits/stdc++.h>

using namespace std;

using ll = long long;

//sum of multiples of 3 or 5 in range [0, N)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1000;

    auto multiplesOf = [&](int x) { //number of multiples of x in range [0, N)
        return (N - 1) / x;
    };

    auto triangular = [](int x) { //1 + 2 + 3 + ... + x
        return x * (x + 1LL) / 2LL;
    };

    cout << triangular(multiplesOf(3)) * 3LL +
            triangular(multiplesOf(5)) * 5LL -
            triangular(multiplesOf(3 * 5)) * 3LL * 5LL << '\n';

    return 0;
}