#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAX_N = 1e7;

bool p[MAX_N];
vector<ll> primes;

void sieve() {
    for (int i = 0; i < MAX_N; i++) {
        p[i] = true;
    }
    p[0] = p[1] = false;
    for (int i = 2; i * i < MAX_N; i++) {
        if (!p[i]) continue;
        for (int j = i * i; j < MAX_N; j += i) {
            p[j] = false;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        if (p[i]) primes.push_back(i);
    }
}

bool isPrime(ll n) {
    if (n < MAX_N) return p[n];
    for (int i : primes) { //we use all the primes < 1e7 so this works for n < 1e14
        if (i * i > n) break;
        if (n % i == 0) return false;
    }
    return true;
}

int consecutivePrimes(int a, int b) {
    int n = 0;
    while (isPrime(1LL * n * n + 1LL * a * n + b)) n++;
    return n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    sieve();
    const int N = 1000;

    pair<int, ll> res = {-1, 0};
    for (int a = -N + 1; a < N; a++) {
        //f(0) = b so b is prime
        for (int b : primes) {
            if (b > N) break;
            res = max(res, {consecutivePrimes(a, b), 1LL * a * b});
        }
    }

    return 0;
}