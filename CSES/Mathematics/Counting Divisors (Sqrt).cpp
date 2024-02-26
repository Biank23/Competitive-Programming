#include <bits/stdc++.h>
 
using namespace std;
 
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) count += 1 + (i * i != n);
    }
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