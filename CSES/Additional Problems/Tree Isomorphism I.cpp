#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using vi = vector<int>;
const int MAX_N = 1e5;
 
map<vi, int> m;
vi adj[MAX_N];
 
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
        int n;
        cin >> n;
        int ans[2];
        for (int i : {0, 1}) {
            for (int j = 1; j < n; j++) {
                int u, v;
                cin >> u >> v;
                --u, --v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            ans[i] = dfs(0);
            for (int j = 0; j < n; j++) {
                adj[j].clear();
            }
        }
        if(ans[0] == ans[1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}