#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
//euler tour
vector<int> adj[MAX_N], euler;
int in[MAX_N];
int height[MAX_N];
 
void dfs(int u, int h = 0) {
    in[u] = ssize(euler);
    euler.push_back(u);
    height[u] = h;
    for (int v : adj[u]) {
        dfs(v, h + 1);
        euler.push_back(u);
    }
}
 
//sparse table
const int MAX_K = 19;
int st[MAX_K][2 * MAX_N];
 
int op(int a, int b) {
    if (height[a] < height[b])
        return a;
    return b;
}
 
void init() {
    int n = ssize(euler);
    for (int i = 0; i < n; i++) {
        st[0][i] = euler[i];
    }
    for (int i = 0, step = 1; i < MAX_K - 1; i++, step *= 2) {
        for (int j = 0; j < n - step; j++) {
            st[i + 1][j] = op(st[i][j], st[i][j + step]);
        }
    }
}
 
int query(int l, int r) {
    if (l > r) swap(l, r);
    r++; //[l, r)
    int log = 31 - __builtin_clz(r - l);
    return op(st[log][l], st[log][r - (1<<log)]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[p - 1].push_back(i);
    }
    dfs(0);
    init();
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << query(in[a], in[b]) + 1 << '\n';
    }
    
    return 0;
}