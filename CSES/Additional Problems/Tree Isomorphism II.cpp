#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using vi = vector<int>;
const int MAX_N = 1e5;
 
map<vi, int> m;
vi adj[MAX_N], centroid;
int sz[MAX_N], n;
 
void find(int u, int p = -1) {
    bool flag = true;
    sz[u] = 1;
    for (int v : adj[u]) if (v != p) {
        find(v, u);
        flag &= sz[v] <= n / 2;
        sz[u] += sz[v];
    }
    flag &= n - sz[u] <= n / 2;
    if (flag) centroid.push_back(u);
}
 
int dfs(int u, int p = -1) {
    vi c;
    for (int v : adj[u]) if (v != p) {
        c.push_back(dfs(v, u));
    }
    sort(all(c));
    if (!m.count(c)) {
        m[c] = ssize(m);
    }
    return m[c];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans[2] = {-1};
        for (int i : {0, 1}) {
            for (int j = 1; j < n; j++) {
                int u, v;
                cin >> u >> v;
                --u, --v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            find(0);
            for (int c : centroid) {
                ans[i] = max(ans[i], dfs(c));
            }
            for (int j = 0; j < n; j++) {
                adj[j].clear();
            }
            centroid.clear();
        }
        if(ans[0] == ans[1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}