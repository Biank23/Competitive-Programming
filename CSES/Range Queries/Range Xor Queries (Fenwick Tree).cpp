#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5+9;
 
int ft[MAX_N];
 
inline int lsb(int i) {
    return i & -i;
}
 
void update(int i, int v) {
    for (++i; i < MAX_N; i += lsb(i)) {
        ft[i] ^= v;
    }
}
 
int query(int i) {
    int res = 0;
    for (; i > 0; i -= lsb(i)) {
        res ^= ft[i];
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        update(i, x);
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int res = query(r) ^ query(l - 1);
        cout << res << '\n';
    }
    
    return 0;
}