#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define eb emplace_back

using vi = vector<int>;
using ii = pair<int, int>;

const int MAX_N = 4e5 + 20;
const int MOD = 1e9 + 7;

int fact[MAX_N], invFact[MAX_N];

int mul(int a, int b){
    return int(1LL * a * b % MOD);
}

int binpow(int a, int k){
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
    invFact[MAX_N - 1] = binpow(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 1; i > 0; i--) {
        invFact[i - 1] = mul(invFact[i], i);
    }
}

int serieparalelo(vi &t, vi &e) {
    int n = sz(e);
    vector<ii> edges, op(n);
    edges.eb(0, 1);
    for (int i = 0; i < n; i++) {
        e[i]--;
        auto [a,b] = edges[e[i]];
        if (t[i] == 1) {
            edges.eb(a, i + 2);
            edges[e[i]] = {i + 2, b};
            op[i] = {sz(edges) - 1, e[i]};
        } else {
            edges.eb(a, i + 2);
            edges.eb(i + 2, b);
            op[i] = {sz(edges) - 2, sz(edges) - 1};
        }
    }
    initFactorials();
    int m = sz(edges);
    vi dp(m, 1), s(m, 0);
    for (int i = n - 1; i >= 0; i--) {
        auto [a,b] = op[i];
        if (t[i] == 1) {
            //L(P; Q) = L(P) * L(Q)
            dp[b] = mul(dp[b], dp[a]);
            s[b] += s[a] + 1;
        } else {
            s[a]++;
            //L(P||Q) = L(P) * L(Q) * (|P| + |Q|)! / (|P|!|Q|!)
            dp[e[i]] = mul(dp[e[i]], mul(dp[a], dp[b]));
            dp[e[i]] = mul(dp[e[i]], fact[s[e[i]] + s[a] + s[b]]);
            dp[e[i]] = mul(dp[e[i]], mul(invFact[s[e[i]]], invFact[s[a] + s[b]]));            
            s[e[i]] += s[a] + s[b];
        }
    }
    return dp.front();
}
