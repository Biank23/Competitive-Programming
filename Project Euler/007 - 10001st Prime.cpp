#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 10001;

    vector<ll> primes{2};
    auto isPrime = [&](ll x) {
        for (ll p : primes) {
            if (p * p > x) break; //we can check only the primes <= sqrt(x)
            if (x % p == 0) return false;
        }
        return true;
    };

    ll x = 3;
    while (sz(primes) < N) {
        if (isPrime(x)) primes.push_back(x);
        x += 2; //the unique even prime is 2
    }
    cout << primes.back() << '\n';

    return 0;
}