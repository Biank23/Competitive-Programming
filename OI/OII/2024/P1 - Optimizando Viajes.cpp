#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
using ii = pair<int, int>;
using ll = long long;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

const int MAX_N = 1e5 + 9;
const ll INF = 2e14;

int n;
vector<ii> adj[MAX_N];

vector<ll> dijkstra(int s) {
    vector<ll> dist(n, INF);
    min_pq<pair<ll, int>> pq;
    pq.emplace(dist[s] = 0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (d + w < dist[v]) pq.emplace(dist[v] = d + w, v);
        }
    }
    return dist;
}

template<typename T>
struct FenwickTree {
    int n;
    vector<T> ft;
    FenwickTree(int _n) : n(_n + 10), ft(n, 0) {}
    void update(int i, T v) {
        for (i++; i < n; i += i & -i) ft[i] += v;
    }
    T query(int i) {
        T s = 0;
        for (i++; i > 0; i -= i & -i) s += ft[i];
        return s;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int m, s, e;
        ll k, l, r;
        cin >> n >> m >> k >> s >> e >> l >> r;
        --s, --e;
        for (int i = 0; i < n; i++) adj[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        vector<ll> distToS = dijkstra(s), distToE = dijkstra(e);
        if (distToS[e] < k) {
            cout << "0\n";
            continue;
        }
        vector<int> nodes(n);
        iota(all(nodes), 0);
        sort(all(nodes), [&](const int &u, const int &v) {
            return distToS[u] - distToE[u] < distToS[v] - distToE[v];
        });
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[nodes[i]] = i;
        vector<ll> vals;
        for (int u : nodes) {
            vals.push_back(distToS[u]);
            vals.push_back(k - distToE[u] - l);
            vals.push_back(k - distToE[u] - r);
        }
        sort(all(vals));
        vals.erase(unique(all(vals)), end(vals));
        int S = sz(vals);
        auto pos = [&](ll v) { return int(lower_bound(all(vals), v) - begin(vals)); };
        ll ans = 0;
        if (distToS[e] == k) {
            FenwickTree<int> ftCant(S);
            FenwickTree<ll> ftSum(S);
            for (int v : nodes) {
                // k - d_s,u - d_v,e >= l: => k - l - d_v,e >= d_s,u
                // r - (k - d_s,u - d_v,e) + 1
                // r - k + d_s,u + d_v,e + 1
                // r - k + 1 + d_v_e + d_s,u
                ans += (r - k + 1 + distToE[v]) * ftCant.query(pos(k - distToE[v] - r), pos(k - distToE[v] - l)) + ftSum.query(pos(k - distToE[v] - r), pos(k - distToE[v] - l));
                ans += (r - l + 1LL) * ftCant.query(pos(k - distToE[v] - l) + 1, S);
                ftCant.update(pos(distToS[v]), 1);
                ftSum.update(pos(distToS[v]), distToS[v]);
            }
            for (int u : nodes) for (auto [v, w] : adj[u]) {
                if (order[u] < order[v] && k - distToS[u] - distToE[v] <= r) {
                    ans -= r - max(k - distToS[u] - distToE[v], (ll) l) + 1;
                }
            }
        } else {
            FenwickTree<int> ft(S);
            for (int v : nodes) {
                // l <= k - d_s,u - d_v,e <= r
                // l - k + d_v,e <= -d_s,u <= r - k + d_v,e
                // k - d_v,e - r <= d_s,u <= k - d_v,e - l
                ans += ft.query(pos(k - distToE[v] - r), pos(k - distToE[v] - l));
                ft.update(pos(distToS[v]), 1);
            }
            for (int u : nodes) for (auto [v, w] : adj[u]) {
                if (order[u] < order[v] && k - distToS[u] - distToE[v] >= l && k - distToS[u] - distToE[v] <= r) ans--;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}