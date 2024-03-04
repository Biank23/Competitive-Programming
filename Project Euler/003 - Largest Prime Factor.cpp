#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const ll N = 600851475143;

    ll n = N;
    ll largestFactor = 1;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            largestFactor = p;
            while (n % p == 0) n /= p;
        }
    }
    if (n != 1) largestFactor = n;
    cout << largestFactor << '\n';

    return 0;
}