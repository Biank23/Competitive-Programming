#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
int mul(int a, int b) {
    return 1LL * a * b % MOD;
}
 
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = mul(res, a);
        }
        a = mul(a, a), b /= 2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << binpow(a, b) << '\n';
    }
    
    return 0;
}