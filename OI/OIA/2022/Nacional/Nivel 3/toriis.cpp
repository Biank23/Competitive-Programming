#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
using vi = vector<int>;

const int MAX_N = 1e5;
const int MOD = 112345687;

void add(int &x, int v) {
    x += v;
    if (x >= MOD) x -= MOD;
}

int mul(int a, int b) {
    return int((ll) a * b % MOD);
}

int binpow(int a, ll k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}

using ii = array<int, 2>;

vector<pair<int, ii>> adj[MAX_N];
int inDeg[MAX_N], outDeg[MAX_N];
ii dp[MAX_N];

int toriis(int N, vi &inicio, vi &fin, vector<ll> &cantidad) {
    int M = sz(cantidad);
    for (int i = 0; i < M; i++) {
        int u = inicio[i] - 1;
        int v = fin[i] - 1;
        ii w = {1, 0};
        if (cantidad[i] != 0) {
            int p = binpow(2, cantidad[i] - 1);
            w = {p, p};
        }
        adj[u].emplace_back(v, w);
        outDeg[u]++, inDeg[v]++;
    }
    
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (inDeg[i] == 0) {
            dp[i] = {1, 0};
            q.push(i);
        } else {
            dp[i] = {0, 0};
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    add(dp[v][i ^ j], mul(dp[u][i], w[j]));
                }
            }
            inDeg[v]--;
            if (inDeg[v] == 0) {
                q.push(v);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (outDeg[i] == 0) {
            add(ans, dp[i][0]);
        }
    }
    
    return ans;
}
