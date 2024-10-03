#include <bits/stdc++.h>
#include "factories.h"
 
using namespace std;
 
using ii = pair<int, int>;
using ll = long long;
 
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"[ ";
    for(auto y : v) out<<y<<" ";
    out<<"]";
    return out;
}
 
const int MAX_N = 5e5 + 9;
 
int sz[MAX_N];
vector<ii> adj[MAX_N];
bitset<MAX_N> done;
 
int getSize(int u, int p = -1) {
    sz[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (v != p && !done[v]) {
            sz[u] += getSize(v, u);
        }
    }
    return sz[u];
}
 
int findCentroid(int u, int size, int p = -1) {
    for (auto [v, w] : adj[u]) {
        if (v != p && !done[v] && sz[v] > size / 2) {
            return findCentroid(v, size, u);
        }
    }
    return u;
}
 
ll dist[20][MAX_N], best[MAX_N];
int par[MAX_N], height[MAX_N];
int t[MAX_N], timer = 0;
 
void dfs(int u, int h, int p = -1, ll d = 0) {
    dist[h][u] = d;
    for (auto [v, w] : adj[u]) {
        if (v != p && !done[v]) dfs(v, h, u, d + w);
    }
}
 
void build(int u, int h = 0, int p = -1) {
    int size = getSize(u);
    u = findCentroid(u, size);
    done[u] = true, par[u] = p, height[u] = h;
    dfs(u, h);
    for (auto [v, w] : adj[u]) {
        if (!done[v]) build(v, h + 1, u);
    }
}
 
void Init(int N, int A[], int B[], int D[]) {
    for (int i = 0; i < N - 1; i++) {
        adj[A[i]].emplace_back(B[i], D[i]);
        adj[B[i]].emplace_back(A[i], D[i]);
    }
    build(0);
}
 
void update(int u) {
    for (int v = u, h = height[u]; v != -1; v = par[v], h--) {
        if (t[v] == timer) best[v] = min(best[v], dist[h][u]);
        else best[v] = dist[h][u], t[v] = timer;
    }
}
 
const ll INF = 1e18;
 
ll query(int u) {
    ll minDist = INF;
    for (int v = u, h = height[u]; v != -1; v = par[v], h--) {
        if (t[v] == timer) minDist = min(minDist, dist[h][u] + best[v]);
    }
    return minDist;
}
 
ll Query(int S, int X[], int T, int Y[]) {
    timer++;
    for (int i = 0; i < S; i++) {
        update(X[i]);
    }
    ll ans = INF;
    for (int i = 0; i < T; i++) {
        ans = min(ans, query(Y[i]));
    }
    return ans;
}