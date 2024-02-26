#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e5 + 9;
 
vector<int> adj[MAX_N];
int par[MAX_N]; // 0 -> not visited
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    q.push(n); //going backwards
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int b : adj[a]) {
            if (par[b] == 0) {
                par[b] = a;
                q.push(b);
            }
        }
    }
    
    if (par[1] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> path{1};
    int a = 1;
    while (a != n) {
        a = par[a];
        path.push_back(a);
    }
    
    cout << ssize(path) << '\n';
    for (int i = 0; i < ssize(path); i++) {
        cout << path[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}