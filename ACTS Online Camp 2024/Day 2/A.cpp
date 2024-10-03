#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 9;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
 
struct Tree {
    int n;
    vector<vi> adj;
    int root, t=-1;
    vi in, out, euler;
    Tree(int _n) : n(_n), adj(n), in(n), out(n) {}
    void dfs(int u) {
        euler.push_back(u);
        in[u] = ++t;
        for (int v : adj[u]) {
            dfs(v);
        }
        out[u] = t;
    }
    void init() {
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            --p;
            if (p == -1) root = i;
            else adj[p].push_back(i);
        }
        dfs(root);
    }
};

int ft[MAX_N];

inline int lsb(int i) {
    return i & (-i);
}

void update(int i) {
    for (i++; i < MAX_N; i += lsb(i)) ft[i]++;
}

int query(int i){
    int s = 0;
    for (i++; i > 0; i -= lsb(i)) s += ft[i];
    return s;
}

int query(int l, int r){
    return query(r) - query(l);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    Tree a(n), b(n);
    a.init(), b.init();
    
    vector<vi> add(n), sub(n);
    for (int i = 0; i < n; i++) {
        sub[b.in[i]].push_back(i);
        add[b.out[i]].push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int u : sub[i]) ans -= query(a.in[u], a.out[u]);
        update(a.in[b.euler[i]]);
        for (int u : add[i]) ans += query(a.in[u], a.out[u]);
    }
    cout << ans << '\n';
    
    return 0;
}