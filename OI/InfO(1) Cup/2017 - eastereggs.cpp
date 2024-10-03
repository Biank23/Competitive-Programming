#include <bits/stdc++.h>
#include "grader.h"
 
using namespace std;
 
const int MAX_N = 512;
 
#define sz(x) int(x.size())
 
vector<int> adj[MAX_N], islands;
 
void dfs(int u, int p = -1) {
    islands.push_back(u + 1);
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
}
 
int findEgg(int N, vector<pair<int, int>> bridges) {
    islands.clear();
    for (int i = 0; i < N; i++) adj[i].clear();
    for (int i = 0; i < N - 1; i++) {
        auto [u, v] = bridges[i];
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    int l = 0, r = N;
    vector<int> v;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        while (sz(v) > m) v.pop_back();
        while (sz(v) < m) v.push_back(islands[sz(v)]);
        if (query(v)) {
            r = m;
        } else {
            l = m;
        }
    }
    return islands[l];
}