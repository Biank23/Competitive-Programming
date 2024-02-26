#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 9;
const int MOD = 1e9 + 7;
 
int fact[MAX_N], inv[MAX_N];
 
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
 
void initFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    inv[MAX_N - 1] = binpow(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 1; i > 0; i--) {
        inv[i - 1] = mul(inv[i], i);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    initFactorials();
    int q; cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << mul(fact[a], mul(inv[b], inv[a - b])) << '\n';
    }
    
    return 0;
}