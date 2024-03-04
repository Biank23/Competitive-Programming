#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

const int MAX_N = 1e5+5;

vector<int> adj[MAX_N];
int down[MAX_N], res[MAX_N], MOD;

int mul(int a, int b) {
    return int((ll) a * b % MOD);
}

int dfsDown(int u, int p = -1) {
    down[u] = 1;
    for (int v : adj[u]) if (v != p) {
        down[u] = mul(down[u], dfsDown(v, u) + 1);
    }
    return down[u];
}

void dfsUp(int u, int p = -1, int up = 1) {
    res[u] = mul(down[u], up);
    int m = sz(adj[u]);
    vector<int> pref(m + 1);
    pref[0] = 1;
    for (int i = 0; i < m; i++) {
        int v = adj[u][i];
        pref[i + 1] = pref[i];
        if (v != p) {
            pref[i + 1] = mul(pref[i + 1], down[v] + 1);
        }
    }
    vector<int> suff(m + 1);
    suff[m] = 1;
    for (int i = m - 1; i >= 0; i--) {
        int v = adj[u][i];
        suff[i] = suff[i + 1];
        if (v != p) {
            suff[i] = mul(suff[i], down[v] + 1);
        }
    }
    for (int i = 0; i < m; i++) {
        int v = adj[u][i];
        if (v != p) {
            dfsUp(v, u, mul(mul(pref[i], suff[i + 1]), up) + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n >> MOD;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfsDown(0);
    dfsUp(0);
    
    for (int i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }
    
    return 0;
}
