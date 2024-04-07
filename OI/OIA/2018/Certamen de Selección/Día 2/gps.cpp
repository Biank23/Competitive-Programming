#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using ii = pair<ll, ll>;

vector<ll> gps(int N, int M, int comienzo, int fin, int K, vi origen, vi destino, vi tiempo) {
    vector<vector<ii>> adj(N);
    for (int i = 0; i < M; i++) {
        adj[origen[i] - 1].emplace_back(destino[i] - 1, tiempo[i]);
    }
    comienzo--, fin--;
    vector<ll> ans;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vi c(N, 0);
    pq.emplace(0, comienzo);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        c[u]++;
        if (c[u] > K) {
            continue;
        }
        if (u == fin) {
            ans.push_back(d);
        }
        for (auto [v, w] : adj[u]) {
            pq.emplace(d + w, v);
        }
    }
    return ans;
}
