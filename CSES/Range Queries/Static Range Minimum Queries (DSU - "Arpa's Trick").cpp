#include <bits/stdc++.h>
 
using namespace std;
 
using ii = pair<int, int>;
using vii = vector<ii>;
 
const int MAX_N = 2e5;
 
int par[MAX_N], sz[MAX_N];
int a[MAX_N], mini[MAX_N];
 
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        sz[i] = 1;
        mini[i] = a[i];
    }
}
 
int find(int x) {
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}
 
void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    mini[x] = min(mini[x], mini[y]);
    par[y] = x;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vii> queries(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries[r].emplace_back(l, i);
    }
    
    vector<int> res(q);
    stack<int> st;
    init(n);
    for (int r = 0; r < n; r++) {
        while (!st.empty() && a[st.top()] > a[r]) {
            unite(st.top(), r);
            st.pop();
        }
        for (auto [l, idx] : queries[r]) {
            res[idx] = mini[find(l)];
        }
        st.push(r);
    }
    
    for (int i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }
    
    return 0;
}
