#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const ll INF = 1e18;
const int MAXN = 20;

ll dp[1 << MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp[0] = 0;
    for (int mask = 1; mask < 1 << n; mask++) {
        ll best = INF;
        for(int s = mask; s > 0; s -= s & -s) {
            int i = __builtin_ctz(s);
            int count = 0;
            for (int j : adj[i]) {
                if (mask >> j & 1) count++;
                else count--;
            }
            best = min(best, dp[mask ^ (1 << i)] + count * __builtin_popcount(mask));
        }
        dp[mask] = best;
    }
    cout << dp[(1 << n) - 1] << '\n';
    
    
    return 0;
}