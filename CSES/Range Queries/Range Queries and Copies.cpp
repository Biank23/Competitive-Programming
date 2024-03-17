#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 8e6;
 
int L[MAX_N], R[MAX_N];
ll val[MAX_N];
 
int n, stSize = 0;
 
void build(vector<int> &x, int u, int l = 0, int r = n) {
    if (r - l <= 1) {
        val[u] = x[l];
        return;
    }
    int m = (l + r) / 2;
    build(x, L[u] = ++stSize, l, m);
    build(x, R[u] = ++stSize, m, r);
    val[u] = val[L[u]] + val[R[u]];
}
 
int update(int p, int v, int u, int l = 0, int r = n) {
    int cur = ++stSize;
    if (r - l <= 1) {
        val[cur] = v;
        return cur;
    }
    int m = (l + r) / 2;
    if (p < m) {
        L[cur] = update(p, v, L[u], l, m);
        R[cur] = R[u];
    } else {
        L[cur] = L[u];
        R[cur] = update(p, v, R[u], m, r);
    }
    val[cur] = val[L[cur]] + val[R[cur]];
    return cur;
}
 
ll query(int s, int e, int u, int l = 0, int r = n) {
    if (e <= l || r <= s) {
        return 0LL;
    }
    if (s <= l && r <= e) {
        return val[u];
    }
    int m = (l + r) / 2;
    return query(s, e, L[u], l, m) +
            query(s, e, R[u], m, r);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> n >> q;
    
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    vector<int> root{0};
    build(t, root[0]);
    
    for (int i = 0; i < q; i++) {
        int type, k;
        cin >> type >> k;
        --k;
        if (type == 3) {
            root.push_back(root[k]);
        } else {
            int a, b;
            cin >> a >> b;
            --a;
            if (type == 1) {
                root[k] = update(a, b, root[k]);
            } else {
                cout << query(a, b, root[k]) << '\n';
            }
        }
    }
    
    return 0;
}