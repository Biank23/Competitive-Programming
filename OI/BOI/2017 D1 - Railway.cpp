#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
using ii = pair<int, int>; 

const int MAX_N = 1e5 + 9;
const int MAX_K = 18;
 
vector<ii> adj[MAX_N];
int up[MAX_K][MAX_N], d[MAX_N];
int in[MAX_N], t = 0;
int idx[MAX_N];
 
void dfs(int u, int p = 0, int h = 0) {
    in[u] = ++t, up[0][u] = p, d[u] = h;
    for (auto [v, i] : adj[u]) {
        if (v != p) {
            idx[v] = i;
            dfs(v, u, h + 1);
        }
    }
}
 
void init(int n) {
    for (int i = 0; i < MAX_K - 1; i++) {
        for (int j = 1; j <= n; j++) {
            up[i + 1][j] = up[i][up[i][j]];
        }
    }
}
 
int lca(int a, int b) {
    if (d[a] < d[b]) {
        swap(a, b);
    }
    int diff = d[a] - d[b];
    for (int i = 0; i < MAX_K; i++) {
        if (diff >> i & 1) a = up[i][a];
    }
    if (a == b) {
        return a;
    }
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}
 
int c[MAX_N], k;
vector<int> ans;
 
void dfs2(int u, int p = 0) {
    for (auto [v, i] : adj[u]) {
        if (v != p) {
            dfs2(v, u);
            c[u] += c[v];
        }
    }
    if (c[u] >= k) ans.push_back(idx[u]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    dfs(1);
    init(n);
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        vector<int> a(s);
        for (int j = 0; j < s; j++) {
            cin >> a[j];
        }
        sort(all(a), [&](const int &x, const int &y) {
            return in[x] < in[y];
        });
        auto nxt = [&s](int j) {
            if (++j == s) j = 0;
            return j;
        };
        for (int j = 0; j < s; j++) {
            int x = a[j], y = a[nxt(j)];
            c[x]++;
            c[lca(x, y)]--;
        }
    }
    dfs2(1);
    cout << sz(ans) << '\n';
    sort(all(ans));
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
