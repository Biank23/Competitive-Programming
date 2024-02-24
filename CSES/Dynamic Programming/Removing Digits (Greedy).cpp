#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    int steps = 0;
    while (n != 0) {
        int num = n, maxDigit = 0;
        while (num > 0) {
            int digit = num % 10;
            maxDigit = max(maxDigit, digit);
            num /= 10;
        }
        n -= maxDigit, steps++;
    }
    cout << steps << '\n';
    
    return 0;
}