#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5;
 
vector<int> adj[MAX_N], adjT[MAX_N];
bitset<MAX_N> vis;
int cmp[MAX_N];
stack<int> order;
 
void topsort(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) topsort(v);
    }
    order.push(u);
}
 
void paint(int u, int color) {
    cmp[u] = color;
    for (int v : adjT[u]) {
        if (!cmp[v]) paint(v, color);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) topsort(i);
    }
    
    int color = 0;
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (!cmp[u]) paint(u, ++color);
    }
    
    cout << color << '\n';
    for (int i = 0; i < n; i++) {
        cout << cmp[i] << ' ';
    }
    
    return 0;
}