#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1000;
 
vector<int> primes;
 
void sieve() {
    bitset<MAX_N> isPrime;
    isPrime.set();
    for (int i = 2; i * i < MAX_N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAX_N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            cerr << i << '\n';
        }
    }
}
 
int countDivisors(int n) {
    int count = 1;
    for (int i : primes) {
        if (i * i > n) break;
        int exponent = 0;
        while (n % i == 0) {
            n /= i, exponent++;
        }
        count *= exponent + 1;
    }
    if (n != 1) count *= 2; //there are a prime p > sqrt(n) with exponent 1
    cerr << '\n';
    return count;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    sieve();
    
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << countDivisors(x) << '\n';
    }
    
    return 0;
}