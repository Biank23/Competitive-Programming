#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 2e6;
    bitset<N> p; //p[i] == 1 if i is prime
    p.set();
    p[0] = p[1] = 0;
    //sieve of eratosthenes
    for (int i = 2; i * i < N; i++) {
        if (!p[i]) continue;
        for (int j = i * i; j < N; j += i) p[j] = 0;
    }

    ll res = 0;
    for (int i = 0; i < N; i++) {
        if (p[i]) res += i;
    }
    cout << res << '\n';

    return 0;
}