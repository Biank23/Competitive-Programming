#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
 
const int MAX_N = 301;
 
vector<int> adj[MAX_N];
bitset<MAX_N> vis;
int match[MAX_N], pairs = 0;
 
bool augPath(int u) {
    if (u == -1) {
        pairs++;
        return true;
    }
    if (vis[u]) {
        return false;
    }
    vis[u] = true;
    for (int v : adj[u]) {
        if (augPath(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<set<string>> v(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            string t;
            cin >> t;
            v[i].insert(t);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool flag = true;
            for (string t : v[j]) {
                if (!v[i].count(t)) {
                    flag = false;
                    break;
                }
            }
            if (flag) adj[i].push_back(j);
        }
    }
    memset(match, -1, sizeof match);
    for (int i = 0; i < n; i++) {
        augPath(i);
        vis.reset();
    }
    cout << n - pairs << '\n';
    
    return 0;
}