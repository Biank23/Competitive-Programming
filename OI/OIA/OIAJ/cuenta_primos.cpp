#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x),end(x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    const int K = 201;
    bitset<K> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < K; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < K; j += i) {
            isPrime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 0; i < K; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    vector<int> freq(K, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int j = int(upper_bound(all(primes), x) - begin(primes));
        while (j < sz(primes)) {
            ans += freq[primes[j] - x];
            j++;
        }
        freq[x]++;
    }
    cout << ans << '\n';
    
    return 0;
}
