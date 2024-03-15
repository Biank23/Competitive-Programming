#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

const int MAX_N = 2e5 + 5;

map<int, int> m[MAX_N];
int c[MAX_N];
vector<int> adj[MAX_N];
ll ans = 0;

void dfs(int u, int p = -1) {
    m[u][c[u]]++;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        ans += m[v][c[u]];
        m[v].erase(c[u]);
        if (sz(m[u]) < sz(m[v])) {
            swap(m[u], m[v]);
        }
        for (auto [val, cnt] : m[v]) {
            ans += 1LL * cnt * m[u][val];
            m[u][val] += cnt;
        }
    }
}

void clear(int n) {
    ans = 0LL;
    for (int i = 0; i < n; i++) {
        adj[i].clear(), m[i].clear();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        cout << ans << '\n';
        clear(n);
    }
    return 0;
}