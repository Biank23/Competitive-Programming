#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using Edge = tuple<int, int, ll>;
 
const ll INF = 1e18;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<Edge> graph(m);
    for (auto &[from, to, weight] : graph) {
        cin >> from >> to >> weight;
    }
    
    vector<ll> dist(n + 1, INF);
    vector<int> par(n + 1, 0);
    
    int lastChange = -1;
    for (int i = 0; i < n && lastChange != 0; i++) {
        lastChange = 0;
        for (auto [from, to, weight] : graph) {
            if (dist[to] > dist[from] + weight) {
                dist[to] = dist[from] + weight;
                par[to] = from;
                lastChange = to;
            }
        }
    }
    
    if (lastChange == 0) {
        cout << "NO\n";
        return 0;
    }
    
    int cur = lastChange;
    for (int i = 0; i < n; i++) {
        cur = par[cur];
    }
    
    int endCycle = cur;
    vector<int> cycle{endCycle};
    do {
        cur = par[cur];
        cycle.push_back(cur);
    } while (cur != endCycle);
    
    cout << "YES\n";
    reverse(all(cycle));
    for (int node : cycle) {
        cout << node << ' ';
    }
    
    return 0;
}