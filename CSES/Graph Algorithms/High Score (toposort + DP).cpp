#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-all-loops", "fast-math", "O3")
#define all(x) begin(x), end(x)
 
using namespace std;
 
using ii = pair<int, int>;
using ll = long long;
 
const int MAX_N = 2500;
const ll INF = 1e18;
 
vector<ii> adj[MAX_N];
vector<int> adjR[MAX_N];
ll sum[MAX_N], dist[MAX_N];
char vis2[MAX_N];
bool vis1[MAX_N];
stack<int> orden;
bool possible = true;
 
void dfs1(int u) {
    vis1[u] = true;
    for (int v : adjR[u]) {
        if (!vis1[v]) dfs1(v);
    }
}
 
void dfs2(int u, ll s = 0) {	
    sum[u] = s, vis2[u] = 1;
    for (auto [v,w] : adj[u]) {
        if (!vis2[v]) {
            dfs2(v, s + w);
        } else if (vis2[v] == 1 && vis1[v] && s + w > sum[v]) {
            possible = false;
        }
    }
    vis2[u] = 2, orden.push(u);
}
 
int SCANF() {
    int n = 0, s = 1;
    char c = getchar_unlocked();
    if (c == '-') {
        s = -1, c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = (n<<1) + (n<<3) + c - '0';
        c = getchar_unlocked();
    }
    return n*s;
}
 
 
int main() {
    int n = SCANF(), m = SCANF();
    for (int i = 0; i < m; i++) {
        int a = SCANF(), b = SCANF(), c = SCANF();
        adj[a - 1].emplace_back(b - 1, c);
        adjR[b - 1].push_back(a - 1);
    }
 
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]), [](const ii &a, const ii &b){
            return a.second > b.second;
        });
    }
 
    dfs1(n - 1);
    dfs2(0);
 
    if (!possible) {
        puts("-1");
        return 0;
    }
 
    for (int i = 1; i < n; i++) {
        dist[i] = -INF;
    }
 
    while (!orden.empty()) {
        int u = orden.top();
        for (auto &[v, w] : adj[u]) {
            dist[v] = max(dist[v], dist[u] + w);
        }
        orden.pop();
    }
 
    printf("%lld", dist[n - 1]);
 
    return 0;
}