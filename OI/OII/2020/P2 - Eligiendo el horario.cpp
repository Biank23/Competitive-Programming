#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Edge {
    int to;
    ll time, start, freq;
    Edge(int v, ll t, ll s, ll f) : to(v), time(t), start(s), freq(f) {}
};

const int MAX_N = 2e5 + 9;

vector<Edge> adj[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    ll l;
    cin >> n >> m >> l;
    while (m--) {
        int from, to;
        ll time, start, freq;
        cin >> from >> to >> time >> start >> freq;
        adj[to].emplace_back(from, time, start + time, freq);
    }
    vector<ll> dist(n, -1);
    priority_queue<pair<ll, int>> pq;
    pq.emplace(dist[n - 1] = l, n - 1);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d < dist[u]) continue;
        for (Edge &e : adj[u]) {
            if (d < e.start) continue;
            ll newDist = e.start + ((d - e.start) / e.freq) * e.freq - e.time;
            if (newDist > dist[e.to]) pq.emplace(dist[e.to] = newDist, e.to);
        }
    }
    cout << dist[0] << '\n';
    
    return 0;
}