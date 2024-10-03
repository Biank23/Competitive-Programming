#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ii = pair<int, int>;

const int MAX_N = 5e5;
const int MOD = 1e9 + 7;

vector<int> adj[MAX_N];
int in[MAX_N], low[MAX_N], timer = 0;
bool vis[MAX_N];
stack<int> st;
vector<vector<int>> components;

void dfs(int u, int p = -1) {
    vis[u] = true, in[u] = low[u] = timer++;
    st.push(u);
    for (int v : adj[u]) if (v != p) {
        if (vis[v]) low[u] = min(low[u], in[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= in[u]) {
                vector<int> cmp{u};
                while (cmp.back() != v) {
                    cmp.push_back(st.top());
                    st.pop();
                }
                components.push_back(cmp);
            }
        }
    }
}

const ii INVALID = {-1, 0LL};
const ii NONE = {0, 0};

int mul(int a, int b) {
    return int(1LL * a * b % MOD);
}

ii check(int id) {
    vector<int> &cmp = components[id];
    sort(all(cmp));
    auto pos = [&](int u) {
        auto it = lower_bound(all(cmp), u);
        if (it == cmp.end() || *it != u) return -1;
        return int(it - begin(cmp));
    };
    vector<int> candidates;
    int n = sz(cmp);
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        int u = cmp[i];
        int j = 0, k = 0;
        while (j < n && k < sz(adj[u])) {
            if (cmp[j] == adj[u][k]) {
                g[i].push_back(j);
                j++, k++;
            } else if (cmp[j] < adj[u][k]) {
                j = int(lower_bound(all(cmp), adj[u][k]) - begin(cmp));
            } else {
                k = int(lower_bound(all(adj[u]), cmp[j]) - begin(adj[u]));
            }
            
        }
        deg[i] = sz(g[i]);
        if (deg[i] > 2) {
            if (sz(candidates) == 2) return INVALID;
            candidates.push_back(i);
        }
    }
    if (sz(candidates) == 0) {
        if (n == 2) return NONE;
        return {n, mul(n, 2)};
    }
    if (sz(candidates) != 2) return INVALID;
    int a = candidates[0], b = candidates[1];
    if (deg[a] != deg[b]) return INVALID;
    queue<int> q;
    vector<int> dist(n, -1);
    dist[a] = 0;
    q.push(a);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int d = dist[b];
    for (int i = 0; i < n; i++) {
        if (i != b && dist[i] >= d) return INVALID;
    }
    return {2 * d, mul(mul(2 * d, deg[a]), deg[a] - 1)};
}

ii &operator+=(ii &x, ii v) {
    if (v == NONE);
    else if (x == NONE) x = v;
    else if (x == INVALID || v == INVALID || x.first != v.first) x = INVALID;
    else if ((x.second += v.second) >= MOD) x.second -= MOD; 
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]));
    }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }
    
    ii ans = NONE;
    for (int i = 0; i < sz(components); i++) {
        ans += check(i);
    }
    if (ans == NONE) cout << "BRAK\n";
    else if (ans == INVALID) cout << "NIE\n";
    else {
        cout << "TAK\n";
        cout << ans.first << ' ' << ans.second << '\n';
    }
    
    return 0;
}