#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_N = 22;
const int MOD = 1000003;

ll d[MOD];
int pos[MOD];

void sieve() {
    for (int i = 1; i < MOD; i++) {
        for (int j = 2 * i; j < MOD; j += i) {
            d[j] += (ll) i * i;
        }
    }
}

int a[MAX_N], prod[1 << MAX_N];
ll dp[1 << MAX_N];

int mul(int a, int b){
    return (ll) a * b % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    sieve();
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    prod[0] = 1;
    for (int mask = 1; mask < 1 << n; mask++) {
        int i = __builtin_ctz(mask);
        prod[mask] = mul(prod[mask ^ (1<<i)], a[i]);
        dp[mask] = d[prod[mask]];
    }
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < 1 << n; mask++) {
            if (mask >> i & 1) dp[mask ^ (1 << i)] += dp[mask];
        }
    }
    while (q--) {
        int k;
        cin >> k;
        int mask = 0;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            mask ^= 1 << pos[x];
        }
        cout << dp[mask] << '\n';
    }
    
    return 0;
}