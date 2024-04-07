#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1020;

bitset<MAX_N> isPrime;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (isPrime[i]) cout << i << '\n';
    }
    
    return 0;
}
