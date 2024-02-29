#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5;
 
vector<int> adj[MAX_N], adjT[MAX_N];
bitset<MAX_N> vis, ans;
int cmp[MAX_N];
stack<int> order;
 
void topsort(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) topsort(v);
    }
    order.push(u);
}
 
void paint(int u, int color) {
    cmp[u] = color;
    for (int v : adjT[u]) {
        if (!cmp[v]) paint(v, color);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> m >> n;
    
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adjT[v].push_back(u);
    };
    
    for (int i = 0; i < m; i++) {
        char wishA, wishB;
        int toppingA, toppingB;
        cin >> wishA >> toppingA >> wishB >> toppingB;
        --toppingA, --toppingB;
        int a = toppingA * 2, b = toppingB * 2;
        if (wishA == '-') a++;
        if (wishB == '-') b++;
        int notA = a ^ 1, notB = b ^ 1;
        addEdge(notA, b);
        addEdge(notB, a);
    }
    
    for (int i = 0; i < 2 * n; i++) {
        if (!vis[i]) topsort(i);
    }
    
    int color = 0;
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (!cmp[u]) paint(u, ++color);
    }
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (cmp[2 * i] == cmp[2 * i + 1]) {
            possible = false;
        }
        ans[i] = cmp[2 * i] > cmp[2 * i + 1];
        
    }
        
    if (possible) {
        for (int i = 0; i < n; i++) {
            if (ans[i]) cout << "+ ";
            else cout << "- ";
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}