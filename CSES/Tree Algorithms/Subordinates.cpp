#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N];
int cant[MAX_N];
 
int dfs(int u) {
    for (int v : adj[u]) {
        cant[u] += dfs(v) + 1;
    }
    return cant[u];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int j;
        cin >> j;
        adj[j - 1].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << cant[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}