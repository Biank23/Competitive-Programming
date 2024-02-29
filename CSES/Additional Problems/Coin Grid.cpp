#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 101;
 
using ii = pair<int, int>;
 
vector<int> adj[MAX_N];
bitset<MAX_N> done, vis[2];
int match[MAX_N];
 
bool augPath(int u) {
    if (!u) return true;
    if (done[u]) return false;
    done[u] = true;
    for (int v : adj[u]) {
        if (augPath(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
 
void dfs(int t, int u) {
    if (vis[t][u]) return;
    vis[t][u] = true;
    if (t) {
        for (int v : adj[u]) {
            dfs(t ^ 1, v);
        }
    } else {
        dfs(t ^ 1, match[u]);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'o') adj[i + 1].push_back(j + 1);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        augPath(i);
        done.reset();
    }
    
    for (int i = 1; i <= n; i++) {
        if (match[i]) done[match[i]] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!done[i]) dfs(1, i);
    }
    
    vector<ii> res;
    for (int i = 1; i <= n; i++) {
        if (vis[0][i]) res.emplace_back(2, i);
        if (!vis[1][i]) res.emplace_back(1, i);
    }
    
    cout << ssize(res) << '\n';
    for (auto [t, u] : res) {
        cout << t << ' ' << u << '\n';
    }
    
    return 0;
}