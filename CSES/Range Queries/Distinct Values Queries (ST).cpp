#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
 
int st[2 * MAX_N], n;
 
void update(int p) {
    p += n;
    while (p > 0) {
        ++st[p];
        p /= 2;
    }
}
 
int query(int l, int r) { // [l, r]
    int res = 0;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res += st[l++];
        if (r % 2 == 0) res += st[r--];
    }
    return res;
}
 
using ii = pair<int, int>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> n >> q;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    map<int,int> pos;
    vector<vector<ii>> queries(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[r - 1].emplace_back(l - 1, i);
    }
    
    vector<int> res(q);
    for (int r = 0; r < n; r++) {
        if (pos.count(x[r])) {
            update(pos[x[r]]);
        }
        pos[x[r]] = r;
        for (auto [l, idx] : queries[r]) {
            res[idx] = (r - l + 1) - query(l, r);
        }
    }
    
    for (int i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }
    
    return 0;
}