#include <bits/stdc++.h>
 
using namespace std;
 
using Node = vector<int>;
 
Node merge(Node &a, Node &b) {
    int n = ssize(a), m = ssize(b);
    Node c(n + m);
    int i = 0, j = 0;
    for (int &x : c) {
        if (j >= m || (i < n && a[i] < b[j])) {
            x = a[i++];
        } else {
            x = b[j++];
        }
    }
    return c;
}
 
const int MAX_N = 2e5 + 9;
 
Node st[2 * MAX_N];
int n;
 
#define all(x) begin(x), end(x)
 
int query(int l, int r, int x) { //[l, r)
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res += int(lower_bound(all(st[l]), x) - begin(st[l]));
            ++l;
        }
        if (r & 1) {
            --r;
            res += int(lower_bound(all(st[r]), x) - begin(st[r]));
        }
    }
    return res;
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
    
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        if (pos.count(x[i])) {
            st[pos[x[i]] + n].push_back(i);
        }
        pos[x[i]] = i;
    }
    
    for (int i = n - 1; i > 0; i--) {
        st[i] = merge(st[2 * i], st[2 * i + 1]);
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        cout << (r - l) - query(l, r, r) << '\n';
    }
    
    return 0;
}
