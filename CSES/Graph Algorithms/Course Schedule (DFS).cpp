#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N];
int vis[MAX_N];
stack<int> order;
bool possible = true;
 
void dfs(int a) {
    vis[a] = 1;
    for (int b : adj[a]) {
        if (!vis[b]) dfs(b);
        possible &= vis[b] != 1;
    }
    order.push(a);
    vis[a] = 2;
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    
    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    while (!order.empty()) {
        cout << order.top() << ' ';
        order.pop();
    }
    
    return 0;
}