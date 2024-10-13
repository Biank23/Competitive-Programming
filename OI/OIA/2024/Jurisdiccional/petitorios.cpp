#include <bits/stdc++.h>

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using namespace std;

int dfs(int u, int T, const vector<vector<int>> &adj) {
    if (sz(adj[u]) == 0) return 1;
    vector<int> valores;
    for (int v : adj[u]) valores.push_back(dfs(v, T, adj));
    sort(all(valores));
    int respuesta = 0;
    for (int i = 0; 100 * i < T * sz(valores); i++) {
        respuesta += valores[i];
    }
    return respuesta;
}

int petitorios(int T, vector<int> &jefes) {
    int n = sz(jefes);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        adj[jefes[i]].push_back(i + 1);
    }
    return dfs(0, T, adj);
}