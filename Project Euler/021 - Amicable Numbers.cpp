#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 10000;

    //d[i] sum of proper divisors of i
    ll d[N] = {0};

    for (int i = 1; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            d[j] += i;
        }
    }

    int res = 0;
    for (int a = 1; a < N; a++) {
        int b = d[a];
        // we check b < a to only count one time each pair
        // also to not count pairs where b >= N
        if (a != b && b < a && d[b] == a) {
            res += a + b;
        }
    }
    cout << res << '\n';

    return 0;
}