#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5+9;
 
ll ft[MAX_N];
 
inline int lsb(int i) {
    return i & -i;
}
 
void update(int i, int v) {
    for (++i; i < MAX_N; i += lsb(i)) {
        ft[i] += v;
    }
}
 
ll query(int i) {
    ll res = 0;
    for (; i > 0; i -= lsb(i)) {
        res += ft[i];
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
        update(i + 1, -x);
    }
    
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(a - 1, u);
            update(b, -u);
        } else {
            int k;
            cin >> k;
            cout << query(k) << '\n';
        }
    }
    
    return 0;
}