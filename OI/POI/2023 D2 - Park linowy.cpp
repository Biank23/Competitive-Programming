#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

void dfs(int u, const vector<vii> &adj, vi &mini, vi &maxi, vi &freq, int res, int p = -1) {
    mini[u] = 1, maxi[u] = res;
    for (auto [v, d] : adj[u]) if (v != p) {
        dfs(v, adj, mini, maxi, freq, res, u);
    }
    for (auto [v, d] : adj[u]) if (v != p) {
        if (d == 1) {
            maxi[u] = min(maxi[u], maxi[v] - 1);
        } else if (d == -1) {
            mini[u] = max(mini[u], mini[v] + 1);
        } else if (mini[v] == maxi[v]) {
            freq[mini[v]]++;
        }
    }
    while (freq[mini[u]] > 0) mini[u]++;
    while (freq[maxi[u]] > 0) maxi[u]--;
    for (auto [v, d] : adj[u]) if (v != p) {
        if (d == 0 && mini[v] == maxi[v]) {
            freq[mini[v]]--;
        }
    }
}

bool check(vector<vii> &adj, int res) {
    int n = sz(adj);
    vi mini(n), maxi(n);
    vi freq(res + 2, 0);
    dfs(0, adj, mini, maxi, freq, res);
    for (int i = 0; i < n; i++) {
        if (mini[i] > maxi[i]) return false;
    }
    return true;
}

int solve_directed(vector<vi> &adj) {
    int n = sz(adj);
    vi deg(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) deg[j]++;
    }
    queue<int> q;
    vi dp(n, 1);
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--deg[v] == 0) q.push(v);
        }
    }
    return *max_element(all(dp));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vii> adj(n);
        vector<vi> g(n);
        for (int i = 1; i < n; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            --a,--b;
            adj[a].emplace_back(b, d);
            adj[b].emplace_back(a, -d);
            if (d == 1) g[a].push_back(b);
        }
        int res = solve_directed(g);
        if (!check(adj, res)) res++;
        cout << res << '\n';
    }
    
    return 0;
}
