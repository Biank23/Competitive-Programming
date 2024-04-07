#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;
using ii = pair<int, int>;

int corto(vi &t, vi &e) {
    vector<ii> edge{{0, 1}};
    int n = sz(e);
    for (int i = 0; i < n; i++) {
        e[i]--;
        auto [A, B] = edge[e[i]];
        edge.emplace_back(A, i + 2);
        if (t[i] == 1) {
            edge[e[i]] = {i + 2, B};
        } else {
            edge.emplace_back(i + 2, B);
        }
    }
    vector<vi> adj(n + 2);
    for (auto [u, v] : edge) {
        adj[u].push_back(v);
    }
    vector<bool> vis(n + 2, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int dist = 0;
    while (!q.empty()) {
        int s = sz(q);
        while (s--) {
            int u = q.front();
            q.pop();
            if (u == 1) {
                return dist;
            }
            for (int v : adj[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        dist++;
    }
    assert(false);
}
