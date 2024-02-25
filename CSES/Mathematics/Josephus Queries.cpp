#include <bits/stdc++.h>
 
using namespace std;
 
int f(int n, int k) {
    int c = (n + 1) / 2;
    if (k > c) {
        int p = f(n - c, k - c);
        if (n % 2 == 1) {
            return 2 * p + 1;
        } else {
            return 2 * p - 1;
        }
    }
    return (2LL * k - 1) % n + 1;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << f(n, k) << '\n';
    }
    
    return 0;
}