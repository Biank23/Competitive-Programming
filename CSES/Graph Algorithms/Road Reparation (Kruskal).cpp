#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
int par[MAX_N], sz[MAX_N];
 
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i, sz[i] = 1;
    }
}
 
int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}
 
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (sz[y] > sz[x]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
    return true;
}
 
using Edge = tuple<int,int,int>;
using ll = long long;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<Edge> graph(m);
    for (auto &[weight, from, to] : graph) {
        cin >> from >> to >> weight;
        --from, --to;
    }
    sort(all(graph));
    
    init(n);
    ll cost = 0;
    int edges = 0;
    for (auto &[weight, from, to] : graph) {
        if (unite(from, to)) {
            cost += weight;
            edges++;
        }
    }
    
    if (edges != n - 1) cout << "IMPOSSIBLE\n";
	else cout << cost << '\n';
    
    return 0;
}