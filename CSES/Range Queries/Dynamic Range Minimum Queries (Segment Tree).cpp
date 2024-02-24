#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5+9;
const int INF = 1e9+20;
 
int st[2*MAX_N], n;
 
void init() {
    for (int i = 0; i < n; i++) {
        cin >> st[i + n];
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = min(st[2 * i], st[2 * i + 1]);
    }
}
 
void update(int i, int val) {
    for (st[i += n] = val; i /= 2;) {
        st[i] = min(st[2 * i], st[2 * i + 1]);
    }
}
 
int query(int l, int r) {
    int res = INF;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res = min(res, st[l++]);
        if (r & 1) res = min(st[--r], res); 
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
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        if (t == 1) {
            update(a, b);
        } else {
            cout << query(a, b) << '\n';
        }
    }
    
    return 0;
}