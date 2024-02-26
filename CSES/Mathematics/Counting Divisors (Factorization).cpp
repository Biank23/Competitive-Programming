#include <bits/stdc++.h>
 
using namespace std;
 
int countDivisors(int n) {
    int count = 1;
    for (int i = 2; i * i <= n; i++) {
        int exponent = 0;
        while (n % i == 0) {
            n /= i, exponent++;
        }
        count *= exponent + 1;
    }
    if (n != 1) count *= 2; //there are a prime p > sqrt(n) with exponent 1
    return count;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << countDivisors(x) << '\n';
    }
    
    return 0;
}