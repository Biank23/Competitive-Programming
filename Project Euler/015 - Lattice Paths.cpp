#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 20;

    //nCr(2*N, N) = (2N)!/(N!N!) = ((N + 1) * (N + 2) * ... * (2N)) / (1 * 2 * ... * N)
    ll res = 1;
    for (int i = 1; i <= N; i++) {
        res *= N + i;
        res /= i;
        //res is divisible for i cause
        //is the multiplication of i consecutive numbers
    }
    cout << res << '\n';

    return 0;
}