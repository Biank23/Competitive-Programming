#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 8e6;
 
int L[MAX_N], R[MAX_N];
ll val[MAX_N];
 
int n, stSize = 0;
 
void build(int u, int l = 0, int r = n) {
    if (r - l <= 1) {
        val[u] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(L[u] = ++stSize, l, m);
    build(R[u] = ++stSize, m, r);
    val[u] = val[L[u]] + val[R[u]];
}
 
int update(int p, int u, int l = 0, int r = n) {
    int cur = ++stSize;
    if (r - l <= 1) {
        val[cur] = 0;
        return cur;
    }
    int m = (l + r) / 2;
    if (p < m) {
        L[cur] = update(p, L[u], l, m);
        R[cur] = R[u];
    } else {
        L[cur] = L[u];
        R[cur] = update(p, R[u], m, r);
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
	
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
	
    vector<int> root{0};
    build(root[0]);
	
    map<int, int> pos;
    for (int r = 0; r < n; r++) {
        if (pos.count(x[r])) {
            root.push_back(update(pos[x[r]], root.back()));
        } else {
            root.push_back(root.back());
        }
        pos[x[r]] = r;
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r, root[r]) << '\n';
    }
	
    return 0;
}
