#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;

const int MAX_N = 1e4 + 9;

vi adj[MAX_N];
int h[MAX_N];

void parse(vector<string> &c) {
    int n = sz(c);
    map<string, int> id, idH;
    for (int i = 0; i < n; i++) {
        string s = "", t = "";
        int j = 0;
        while (c[i][j] != '!') {
            assert(j < sz(c[i]));
            s += c[i][j];
            j++;
        }
        while (c[i][j] != '=') {
            assert(j < sz(c[i]));
            t += c[i][j];
            j++;
        }
        id[s + t] = i;
        if (!idH.count(t)) {
            idH[t] = sz(idH);
        }
        h[i] = idH[t];
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (c[i][j] != '=') j++;
        while (j < sz(c[i])) {
            while (j < sz(c[i]) && !isalpha(c[i][j])) {
                j++;
            }
            string s = "";
            while (j < sz(c[i]) && (isalnum(c[i][j]) || c[i][j] == '!')) {
                s += c[i][j];
                j++;
            }
            if (s != "") {
                assert(id.count(s));
                adj[id[s]].push_back(i);
            }
            
        }
    }
}

bitset<MAX_N> vis[MAX_N];

void dfs(int u) {
    vis[u][u] = true;
    for (int v : adj[u]) {
        if (!vis[v][v]) dfs(v);
        vis[u] |= vis[v];
    } 
}

void celdas(vector<string> &c, vi &celdasTotal, vi &celdasMismaHoja) {
    parse(c);
    int n = sz(c);
    for (int i = 0; i < n; i++) {
        if (!vis[i][i]) dfs(i);
    }
    celdasTotal.resize(n);
    celdasMismaHoja.assign(n, 0);
    for (int i = 0; i < n; i++) {
        celdasTotal[i] = int(vis[i].count()) - 1;
        for (size_t j = vis[i]._Find_first(); j < vis[i].size() ; j = vis[i]._Find_next(j)) {
            if (int(j) != i && h[i] == h[j]) celdasMismaHoja[i]++;
        }
    }
}
