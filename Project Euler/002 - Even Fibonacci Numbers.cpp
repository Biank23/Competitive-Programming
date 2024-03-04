#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 4e6;

    ll res = 0;
    ll f0 = 1, f1 = 1;
    while (f0 <= N) {
        //f[i] = f[i - 1] + f[i - 2]
        tie(f0, f1) = make_pair(f0 + f1, f0);
        if (f0 % 2 == 0) res += f0;
    }
    cout << res << '\n';

    return 0;
}