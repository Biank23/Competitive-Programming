#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

vector<int> buscaprimos(string &s) {
    const int N = 1e5;
    bitset<N> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++) {
        for (int j = i * i; j < N; j += i) {
            isPrime[j] = false;
        }
    }
    set<string> primes;
    for (int i = 0; i < N; i++) {
        if (isPrime[i]) primes.insert(to_string(i));
    }
    const int K = 4;
    vector<int> ans(K, 0);
    for (int k = 1; k <= K; k++) {
        for (int i = 0; i <= sz(s) - k; i++) {
            string num = s.substr(i, k);
            if (primes.count(num)) {
                ans[k - 1]++;
            }
        }
    }
    return ans;
}
