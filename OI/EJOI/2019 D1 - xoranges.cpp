#include <bits/stdc++.h>
 
using namespace std;
 
struct FTree {
    int n;
    vector<int> ft;
    FTree(int _n) : n(_n + 9), ft(n, 0) {}
    inline int lsb(int i) {
        return i & (-i);
    }
    void update(int i, int v) {
        for (++i; i < n; i += lsb(i)) {
            ft[i] ^= v;
        }
    }
    int query(int i) {
        int r = 0;
        for (++i; i > 0; i -= lsb(i)) {
            r ^= ft[i];
        }
        return r;
    }
    int query(int l, int r) {
        return query(r) ^ query(l - 1);
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<FTree> ft(2, FTree(n));
    for (int i = 0; i < n; i++) {
        ft[i % 2].update(i, a[i]);
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            --x;
            ft[x % 2].update(x, y ^ a[x]);
            a[x] = y;
        } else {
            --x, --y;
            if ((y - x) % 2 == 1) {
                cout << "0\n";
            } else {
                cout << ft[x % 2].query(x, y) << '\n';
            }
        }
    }
    
    return 0;
}