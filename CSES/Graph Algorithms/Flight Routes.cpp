#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ii = pair<ll, ll>;
 
const int MAX_N = 1e5;
 
vector<ii> adj[MAX_N];
int cant[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
    }
    
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, 0);
    vector<ll> res;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        cant[u]++;
        if (cant[u] > k) {
            continue;
        }
        if (u == n - 1) {
            res.push_back(d);
        }
        for (auto [v, w] : adj[u]) {
            pq.emplace(d + w, v);
        }
    }
    
    for (int i = 0; i < k; i++) {
        cout << res[i] << ' ';
    }
    
    return 0;
}