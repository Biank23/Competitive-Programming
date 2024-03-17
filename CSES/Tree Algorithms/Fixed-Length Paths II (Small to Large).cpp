#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5+9;
 
deque<ll> dq[MAX_N];
vector<int> adj[MAX_N];
int n, a, b;
ll res = 0LL;
 
ll query(int u, int l, int r) {
    ll ans = 0LL;
    l = max(0, l), r = max(0, r + 1);
    if (l < ssize(dq[u])) {
        ans += dq[u][l];
    }
    if (r < ssize(dq[u])) {
        ans -= dq[u][r];
    }
    return ans;
}
void dfs(int u, int p = -1) {
    dq[u].push_back(1);
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        dq[v].push_front(dq[v].front());
        if (ssize(dq[v]) > ssize(dq[u])) {
            swap(dq[u], dq[v]);
        }
        for (int i = 0; i < ssize(dq[v]); i++) {
            res += query(u, a - i, b - i) * query(v, i, i);
        }
        for (int i = 0; i < ssize(dq[v]); i++) {
            dq[u][i] += dq[v][i];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << res << '\n';
    
    return 0;
}