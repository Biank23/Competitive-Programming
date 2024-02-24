#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5+9;
 
int st[2*MAX_N], n;
 
void init() {
    for (int i = 0; i < n; i++) {
        cin >> st[i + n];
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = st[2 * i] ^ st[2 * i + 1];
    }
}
 
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res ^= st[l++];
        if (r & 1) res ^= st[--r]; 
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin >> n >> q;
    init();
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r) << '\n';
    }
    
    return 0;
}