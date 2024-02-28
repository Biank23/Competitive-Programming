#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N];
int o[MAX_N];
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        o[a]++;
    }
    
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (!o[i]) pq.push(i);
    }
    
    vector<int> order;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            o[v]--;
            if (!o[v]) pq.push(v);
        }
    }
    
    reverse(all(order));
    for (int i = 0; i < n; i++) {
        cout << order[i] << ' ';
    }
    
    return 0;
}