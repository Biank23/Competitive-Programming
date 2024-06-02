#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
using vi = vector<int>;

const int INF = 2e9;

int editora(vi &tinta, vector<ll> &articulos, string &ordenamiento) {
    const int N = sz(articulos);
    vi p(N);
    iota(all(p), 0);
    const int M = 1 << N;
    vi dp(M, INF), par(M, -1), cost(M);
    vector<ll> sum(M);
    dp[0] = 0;
    sum[0] = 1;
    cost[0] = tinta[1];
    for (int mask = 1; mask < M; mask++) {
        int bit = __builtin_ctz(mask);
        sum[mask] = sum[mask ^ (1 << bit)] + articulos[bit];
        ll x = sum[mask];
        int v = 0;
        do v += tinta[x % 10];
        while (x /= 10);
        cost[mask] = v;
        for (int submask = mask; submask > 0; submask -= submask & -submask) {
            int i = __builtin_ctz(submask);
            int curr = dp[mask ^ (1 << i)] + cost[mask ^ (1 << i)];
            if (dp[mask] > curr) dp[mask] = curr, par[mask] = i;
        }
    }
    ordenamiento = "";
    int mask = M - 1;
    for (int i = 0; i < N; i++) {
        int j = par[mask];
        ordenamiento += char('A' + j);
        mask ^= 1 << j;
    }
    reverse(all(ordenamiento));
    return dp[M - 1];
}
