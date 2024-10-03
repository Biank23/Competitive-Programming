#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;

const int MAX_N = 222;
const int INF = 1e9;

bool adj[MAX_N][MAX_N], g[MAX_N][MAX_N], vis[MAX_N], done[2][MAX_N];
int dist[MAX_N][MAX_N], c[MAX_N], match[MAX_N], lvl[MAX_N], n;
vi nodes[2], visited;

void color(int u, int k) {
    c[u] = k, visited.push_back(u);
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !c[v]) color(v, 3 - k);
    }
}


bool augPath(int u) {
    if (u == -1) return true;
    if (vis[u]) return false;
    vis[u] = true;
    for (int v = 0; v < sz(nodes[1]); v++) {
        if (g[u][v] && augPath(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

void dfs(int u, int p) {
    if (done[p][u]) return;
    done[p][u] = true;
    if (p == 1) {
        dfs(match[u], 0);
    } else {
        for (int v = 0; v < sz(nodes[1]); v++) {
            if (g[u][v] && match[v] != u) dfs(v, 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, k;
    cin >> n >> m >> k;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u][v] = adj[v][u] = true;
    }
    for (int i = 0; i < n; i++) if (!c[i]) {
        visited.clear();
        color(i, 1);
        vi cnt(2, 0);
        for (int u : visited) {
            cnt[c[u] - 1]++;
        }
        if (cnt[0] < cnt[1]) {
            for (int u : visited) c[u] = 3 - c[u];
        }
    }
    bool flag = true;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            flag &= !adj[u][v] || c[u] != c[v];
        }
    }
    if (!flag) {
        cout << "NIE\n";
        return 0;
    }
    if (k % 2 == 1) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += c[i] == 1;
        }
        cout << res << '\n';
        for (int i = 0; i < n; i++) {
            cout << c[i] << ' ';
        }
        cout << '\n';
        return 0;
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u == v) dist[u][v] = 0;
            else if (adj[u][v]) dist[u][v] = 1;
            else dist[u][v] = INF;
        }
    }
    for (int w = 0; w < n; w++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
            }
        }
    }
    for (int u = 0; u < n; u++) {
        nodes[c[u] - 1].push_back(u);
    }
    for (int i = 0; i < sz(nodes[0]); i++) {
        int u = nodes[0][i];
        for (int j = 0; j < sz(nodes[1]); j++) {
            int v = nodes[1][j];
            g[i][j] = dist[u][v] < k - 1;
        }
    }
    for (int j = 0; j < sz(nodes[1]); j++) {
        match[j] = -1;
    }
    for (int i = 0; i < sz(nodes[0]); i++) {
        for (int j = 0; j < sz(nodes[0]); j++) {
            vis[j] = false;
        }
        augPath(i);
    }
    int res = n;
    vector<bool> matched(sz(nodes[0]), false);
    for (int j = 0; j < sz(nodes[1]); j++) {
        if (match[j] != -1) {
            res--;
            matched[match[j]] = true;
        }
    }
    for (int i = 0; i < sz(nodes[0]); i++) {
        if (!matched[i]) dfs(i, 0);
    }
    cout << res << '\n';
    for (int i = 0; i < n; i++) {
        lvl[i] = -1;
    }
    queue<int> q;
    for (int i = 0; i < sz(nodes[0]); i++) {
        if (!done[0][i]) continue;
        q.push(nodes[0][i]);
        lvl[nodes[0][i]] = 1;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && lvl[v] == -1) {
                q.push(v);
                lvl[v] = lvl[u] + 1;
                if (lvl[v] > k) lvl[v] -= 2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (lvl[i] == -1) lvl[i] = c[i];
        cout << lvl[i] << ' ';
    }
    cout<<'\n';
    
    return 0;
}