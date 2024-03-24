#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x),end(x)

using vi = vector<int>;

struct DSU {
    vi par;
    DSU(int n) : par(n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int find(int x){
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }
    void unite(int x, int y){
        x = find(x), y = find(y);
        if (x == y) return;
        par[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        DSU dsu(n);
        vector<vi> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            if (u < v) {
                swap(u,v);
            }
            adj[u].push_back(v);
        }
        vi color(n);
        for (int u = 0; u < n; u++) {
            set<int> components, cycles;
            for (int v : adj[u]) {
                int comp = dsu.find(v);
                if (components.count(comp)) {
                    cycles.insert(color[v]);
                } else {
                    components.insert(comp);
                }
            }
            int prev = 0;
            for(int curr : cycles){
                if(curr != prev + 1) {
                    break;
                }
                prev = curr;
            }
            color[u] = prev + 1;
            for (int v : adj[u]) {
                if (color[u] == color[v]) dsu.unite(u, v);
            }
        }
        cout << "SI " << *max_element(all(color)) << '\n';
        for (int i = 0; i < n; i++) {
            cout << color[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
