#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAX_N = 1e4 + 9;
const ll INF = 1e18;
const int S = 3;

ll dist[MAX_N][S];
ii par[MAX_N][S];

vector<pair<ii, bool>> adj[MAX_N];

int main() {
    freopen("ciudad.in", "r", stdin);
	freopen("ciudad.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m[2];
    cin >> n >> m[0] >> m[1];
    
    map<ii, int> id;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= m[i]; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            adj[u].emplace_back(ii{v, w}, i);
            adj[v].emplace_back(ii{u, w}, i);
            if (i) id[{u, v}] = id[{v, u}] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < S; j++) {
            dist[i][j] = INF;
        }
    }
    priority_queue<pair<ll, ii>, vector<pair<ll, ii>>, greater<pair<ll, ii>>> pq;
    pq.emplace(dist[n - 1][0] = 0, ii{n - 1, 0});
    par[n - 1][0] = {-1, 0};
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        auto [x, c] = u;
        if (d > dist[x][c]) continue;
        for (auto [e, t] : adj[x]) {
            auto [y, w] = e;
            if (c + t < S && dist[y][c + t] > d + w) {
                pq.emplace(dist[y][c + t] = d + w, ii{y, c + t});
                par[y][c + t] = {x, c};
            }
        }
    }
    int x = 0, c = -1;
    ll ans = INF;
    for (int i = 0; i < S; i++) {
        ans = min(ans, dist[x][i]);
    }
    for (int i = 0; i < S; i++) {
        if (ans == dist[x][i]) {
            c = i;
            break;
        }
    }
    assert(c != -1);
    cout << char('1' + c) << ' ';
    while (x != -1) {
        auto [nx, nc] = par[x][c];
        if (nc != c) {
            assert(id.count({x, nx}));
            cout << id[{x, nx}] << ' ';
        }
        x = nx, c = nc;
    }
    cout << ans << '\n';
    
    return 0;
}
