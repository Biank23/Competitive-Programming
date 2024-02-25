#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
inline int mul(int a, int b, const int m) {
    return 1LL * a * b % m;
}
 
int binpow(int a, int b, const int m) {
    if (b == 0) return 1;
    int res = binpow(mul(a, a, m), b / 2, m);
    if (b % 2 == 1) res = mul(a, res, m);
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow(b, c, MOD - 1), MOD) << '\n';
    }
    
    return 0;
}