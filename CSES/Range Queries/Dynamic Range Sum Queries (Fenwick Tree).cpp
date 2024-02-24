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
    ll sum = 0;
    for (; i > 0; i -= lsb(i)) {
        sum += ft[i];
    }
    return sum;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        update(i, x[i]);
    }
    
    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        if (t == 1) {
            update(a, b-x[a]);
            x[a] = b;
        } else {
            cout << query(b) - query(a) << '\n';
        }
    }
    
    return 0;
}