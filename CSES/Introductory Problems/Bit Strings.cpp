#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MOD = 1e9 + 7;
 
int mul(int a, int b) {
    return (ll) a * b % MOD;
}
 
int binpow(int a, int k) {
    int res = 1;
    while (k > 0) {
        if (k % 2 == 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        k /= 2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    cout << binpow(2, n) << '\n';
    
    return 0;
}
