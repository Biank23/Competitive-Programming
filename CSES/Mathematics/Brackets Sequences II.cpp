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
 
int C(int n, int k) {
    return mul(fact[n], mul(inv[k], inv[n - k]));
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    initFactorials();
    
    int n;
	string s;
	cin >> n >> s;
	
    int m = ssize(s), c = 0;
	bool possible = true;
	for (int i = 0; i < m; i++) {
		if (s[i] == '(') c++;
		else c--;
		if (c < 0) possible = false;
	}
	
    n -= m;
	if ((n - c) % 2 == 1 || !possible) {
		cout << "0\n";
		return 0;
	}
    
    int k = (n - c) / 2;
    cout << mul(C(n, k), mul(c + 1, binpow(k + c + 1, MOD - 2))) << '\n';
    
    
    return 0;
}