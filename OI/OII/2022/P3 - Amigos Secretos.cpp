#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAX_N = 1e6 + 9;

int fact[MAX_N], invFact[MAX_N];

int mul(int a, int b) {
    return 1LL * a * b % MOD;
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
        fact[i] = mul(i, fact[i - 1]);
    }
    invFact[MAX_N - 1] = binpow(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 1; i > 0; i--) {
        invFact[i - 1] = mul(i, invFact[i]);
    }
}

int dp[MAX_N], pref[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    initFactorials();
    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < k; i++) {
        pref[i] = mul(invFact[i], dp[i]);
    }
    for (int i = 1; i < k; i++) {
        pref[i] += pref[i - 1];
        if (pref[i] >= MOD) pref[i] -= MOD;
    }
    for (int i = k; i <= n; i++) {
        dp[i] = mul(fact[i - 1], pref[i - k]);
        pref[i] = pref[i - 1] + mul(invFact[i], dp[i]);
        if (pref[i] >= MOD) pref[i] -= MOD;
    }
    cout << dp[n] << '\n';
    
    return 0;
}