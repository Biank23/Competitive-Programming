#include <bits/stdc++.h>

#define sz(x) int(x.size())

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

ii operator+(ii a, ii b) {
    return {a.first + b.first, a.second + b.second};
}

const ll INF = 1e18;

vector<ll> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m) {
    vector<vector<pair<int, ii>>> adj(N);
    for (int i = 0; i < sz(a); i++) {
        a[i]--, b[i]--;
        adj[a[i]].emplace_back(b[i], ii{d[i], 0});
        if (m[i] != -1) adj[a[i]].emplace_back(b[i], ii{0, m[i]});
    }
    priority_queue<pair<ii, int>, vector<pair<ii, int>>, greater<pair<ii, int>>> pq;
    vector<ii> dist(N, {INF, INF});
    pq.emplace(dist[0] = {0, 0}, 0);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] != d) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) pq.emplace(dist[v] = d + w, v); 
        }
    }
    return vector<ll>{dist[N - 1].first, dist[N - 1].second};
}