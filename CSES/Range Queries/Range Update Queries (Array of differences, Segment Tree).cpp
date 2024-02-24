#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5+9;
 
ll st[2*MAX_N];
int n;
 
void init(vector<int> &diff) {
    for (int i = 0; i < n; i++) {
        st[i + n] = diff[i];
    }
    for (int i = n - 1; i > 0; i--) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
}
 
void update(int i, int val) {
    for (st[i += n] += val; i /= 2;) {
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
    n++;
    vector<int> diff(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        diff[i] += x;
        diff[i + 1] -= x;
    }
    init(diff);
    
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
            cout << query(0, k) << '\n';
        }
    }
    
    return 0;
}