#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 9;
 
int mul(int a, int b) {
    return int(1LL * a * b % MOD);
}
 
int binpow(int a, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}
 
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
 
int powM[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    powM[0] = 1;
    for (int i = 1; i <= n; i++) {
        powM[i] = mul(powM[i - 1], m);
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += powM[gcd(n, i)];
        if (res >= MOD) res -= MOD;
    }
    
    cout << mul(res, binpow(n, MOD - 2)) << '\n';
    
    return 0;
}