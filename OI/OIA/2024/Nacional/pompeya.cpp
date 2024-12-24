#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

struct Point {
    ll x, y;
    Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    Point operator-(const Point &o) {
        return {x - o.x, y - o.y};
    }
    ll operator^(const Point &o) { //producto cruz
        return x * o.y - y * o.x;
    }
    ll abs() const {
        return x * x + y * y;
    }
    int half() const {
        return int(y < 0 || (y == 0 && x < 0));
    }
};

const int INF = 1e9;

vi pompeya(vi &x, vi &y, vi &a, vi &b, vi &t) {
    int maxX = max_element(all(x)) - x.begin();
    x.push_back(x[maxX] + 1);
    y.push_back(y[maxX]);
    a.push_back(maxX);
    b.push_back(sz(x) - 1);
    t.push_back(1);
    int n = sz(x), m = sz(a);
    vector<vector<ii>> adj(n);
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {x[i], y[i]};
    }
    for (int i = 0; i < m; i++) {
        adj[a[i]].emplace_back(b[i], 2 * i);
        adj[b[i]].emplace_back(a[i], 2 * i + 1);
    }
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]), [&](const ii &lhs, const ii &rhs) {
            Point pl = p[lhs.first] - p[i];
            Point pr = p[rhs.first] - p[i];
            if (pl.half() != pr.half()) return pl.half() < pr.half();
            if ((pl ^ pr) == 0) return pl.abs() < pr.abs();
            return (pl ^ pr) > 0;
        });
    }
    vector<int> pos(2 * m);
    for (int u = 0; u < n; u++) for (int i = 0; i < sz(adj[u]); i++) {
        pos[adj[u][i].second] = i;
    }
    vi vis(2 * m, 0);
    int r = 0;
    for (int i = 0; i < n; i++) for (auto [u, id] : adj[i]) {
        if (vis[id]) continue;
        r++;
        while (!vis[id]) {
            vis[id] = r;
            int j = (pos[id ^ 1] + 1) % sz(adj[u]);
            tie(u, id) = adj[u][j];
        }
    }
    for (int i = 0; i < 2 * m; i++) {
        assert(vis[i] > 0);
        vis[i]--;
    }
    vector<vi> g(r);
    for (int i = 0; i < m; i++) {
        if (t[i]) continue;
        int u = vis[2 * i], v = vis[2 * i + 1];
        g[u].push_back(v), g[v].push_back(u);
    }
    vi dist(r, INF);
    queue<int> q;
    assert(vis[2 * m - 2] == vis[2 * m - 1]);
    int inicio = vis[2 * m - 1];
    dist[inicio] = 0;
    q.push(inicio);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int noVisitados = 0, maxDist = 0;
    for (int i = 0; i < r; i++) {
        if (dist[i] == INF) noVisitados++;
        else maxDist = max(maxDist, dist[i]);
    }
    return {maxDist, noVisitados};
}
