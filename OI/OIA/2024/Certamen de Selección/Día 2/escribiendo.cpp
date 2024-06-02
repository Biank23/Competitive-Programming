#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

inline ll remtz(ll x) {
    return x >> __builtin_ctzll(x);
}

ll gcdOdd(ll a, ll b) {
    while (a != b) {
        if (a < b) swap(a, b);
        a = remtz(a - b);
    }
    return a;
}

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return gcdOdd(remtz(a), remtz(b)) << min(__builtin_ctzll(a), __builtin_ctzll(b));
}

const int MAX_N = 1500;
const ll INF = 2e18;

ll cost[MAX_N][MAX_N], dist[MAX_N];
bitset<MAX_N> done;

ll escribiendo(ll C, vector<ll> &numeros) {
    int n = sz(numeros);
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        for (int j = 0; j < i; j++) {
            ll commonDivisor = gcd(numeros[i], numeros[j]);
            cost[i][j] = cost[j][i] = min(C, (numeros[i] + numeros[j]) / commonDivisor);
        }
    }
    dist[0] = C;
    for (int i = 0; i < n; i++) {
        pair<ll, int> minDist = {INF, -1};
        for (int u = 0; u < n; u++) {
            if (!done[u]) minDist = min(minDist, {dist[u], u});
        }
        int u = minDist.second;
        done[u] = true;
        for (int v = 0; v < n; v++) {
            if (!done[v] && dist[v] > cost[u][v]) {
                dist[v] = cost[u][v];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dist[i];
    }
    return ans;
}
