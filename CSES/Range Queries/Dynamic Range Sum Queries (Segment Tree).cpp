#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5+9;
 
ll st[2*MAX_N];
int n;
 
void init() {
    for (int i = 0; i < n; i++) {
        cin >> st[i + n];
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
}
 
void update(int i, int val) {
    for (st[i += n] = val; i /= 2;) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
}
 
ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res += st[l++];
        if (r & 1) res += st[--r]; 
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