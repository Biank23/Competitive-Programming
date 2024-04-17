#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int(x.size())
 
const int MAX_N = 300;
const int INF = 1e9;
 
using ii = pair<int, int>;
 
int capacity[MAX_N][MAX_N];
vector<int> adj[MAX_N];
int par[MAX_N];
 
bool bfs(int s, int e) {
    queue<int> q;
    memset(par, -1, sizeof par);
    q.push(s), par[s] = -2;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && par[v] == -1) {
                q.push(v), par[v] = u;
            }
        }
    }
    return par[e] != -1;
}
 
void maxFlow(int s, int e) {
    while (bfs(s, e)) {
        int flow = INF;
        for (int u = e; u != s; u = par[u]) {
            flow = min(flow, capacity[par[u]][u]);
        }
        for (int u = e; u != s; u = par[u]) {
            capacity[par[u]][u] -= flow;
            capacity[u][par[u]] += flow;
        }
    }
}

void addEdge(int u, int v, int w) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] += w;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    int s = 0, e = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        addEdge(s, i, a);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            addEdge(i, j, 1);
        }
    }
    for (int j = n + 1; j <= 2 * n; j++) {
        int b;
        cin >> b;
        addEdge(j, e, b);
    }
    maxFlow(s, e);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (capacity[s][i]) flag = false;
    }
    for (int j = n + 1; j <= 2 * n; j++) {
        if (capacity[j][e]) flag = false;
    }
    if (!flag) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            if (capacity[j][i]) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
    
    
    return 0;
}
