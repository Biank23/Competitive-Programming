#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N];
int o[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        o[b]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!o[i]) q.push(i);
    }
    
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            o[v]--;
            if (!o[v]) q.push(v);
        }
    }
    
    if (ssize(order) != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        cout << order[i] << ' ';
    }
    
    return 0;
}