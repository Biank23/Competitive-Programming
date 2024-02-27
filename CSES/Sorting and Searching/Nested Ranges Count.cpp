#include <bits/stdc++.h>
 
using namespace std;
 
struct Range {
    int l, r, idx;
};
 
#define all(x) begin(x), end(x)
 
const int MAX_N = 2e5 + 9;
 
int ans[MAX_N];
 
void print(int n) {
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
 
inline int lsb(int i) {
    return i & (-i);
}
 
struct FTree {
    int ft[MAX_N];
    FTree() {
        memset(ft, 0, sizeof ft);
    }
    void update(int i) {
        for (++i; i < MAX_N; i += lsb(i)) {
            ++ft[i];
        }
    }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= lsb(i)) {
            res += ft[i];
        }
        return res;
    }
    int query(int l, int r) { // [l, r]
        return query(r) - query(l - 1);
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<Range> v(n);
    vector<int> coords(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        coords[i] = v[i].r;
        v[i].idx = i;
    }
    sort(all(coords));
    coords.erase(unique(all(coords)), end(coords));
    
    sort(all(v), [](const Range &lhs, const Range &rhs) {
        if (lhs.l != rhs.l) return lhs.l > rhs.l;
        return lhs.r < rhs.r;
    });
    
    FTree ft1;
    for (int i = 0; i < n; i++) {
        int right = int(lower_bound(all(coords), v[i].r) - begin(coords));
        ans[v[i].idx] = ft1.query(right);
        ft1.update(right);
    }
    print(n);
    
    FTree ft2;
    for (int i = n - 1; i >= 0; i--) {
        int right = int(lower_bound(all(coords), v[i].r) - begin(coords));
        ans[v[i].idx] =  ft2.query(right, n);
        ft2.update(right);
    }
    print(n);
    
    return 0;
}
