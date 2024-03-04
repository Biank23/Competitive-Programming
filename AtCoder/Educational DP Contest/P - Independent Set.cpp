#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
#define fst first
#define snd second

const int MAXN = 1e5;
const int MOD = 1e9+7;

vector<int> adj[MAXN];

ii& operator*=(ii &a, const ii &b) {
    a.fst = 1LL * a.fst * b.snd % MOD;
    a.snd = 1LL * a.snd * b.fst % MOD;
    return a;
}

ii dfs(int u, int p = -1) {
    ii res = {1, 1};
    for (int v : adj[u]) {
        if (v != p) res *= dfs(v, u);
    }
    res.fst += res.snd;
    if (res.fst >= MOD) res.fst -= MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(0).fst << '\n';
    
    return 0;
}