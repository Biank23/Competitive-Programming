#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 1e18;
const int L = 1001;

vector<ll> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m) {
    vector<vector<tuple<int, int, int>>> adj(N);
    for (int i = 0; i < sz(a); i++) {
        a[i]--, b[i]--;
        adj[a[i]].emplace_back(b[i], 0, d[i]);
        if (m[i] != -1) adj[a[i]].emplace_back(b[i], m[i], 0);
    }
    priority_queue<pair<ll, ii>, vector<pair<ll, ii>>, greater<pair<ll, ii>>> pq;
    vector<vector<ll>> dist(N, vector<ll>(L, INF));
    pq.emplace(dist[0][0] = 0, ii{0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        auto [c, m] = u;
        pq.pop();
        if (dist[c][m] != d) continue;
        for (auto [v, w1, w2] : adj[c]) {
            if (m + w1 < L && dist[v][m + w1] > d + w2) {
                pq.emplace(dist[v][m + w1] = d + w2, ii{v, m + w1});
            }
        }
    }
    vector<ll> respuesta = {INF, INF};
    for (int i = 0; i < L; i++) {
        respuesta = min(respuesta, {dist[N - 1][i], i});
    }
    return respuesta;
}