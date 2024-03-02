#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
 
const int MAX_N = 2e5 + 9;
 
int ft[MAX_N];
 
inline int lsb(int i) {
    return i & (-i);
}
 
void update(int i, int v) {
    ++i;
    while (i < MAX_N) {
        ft[i] += v;
        i += lsb(i);
    }
}
 
int query(int i) { //[0, i)
    int s = 0;
    while (i > 0) {
        s += ft[i];
        i -= lsb(i);
    }
    return s;
}
 
int query(int l, int r) { //[l, r)
    return query(r) - query(l);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        update(i, 1);
        p[i] = i;
    }
    sort(all(p), [&](const int &a, const int &b) {
        return x[a] < x[b];
    });
    ll moves = 0;
    for (int i : p) {
        moves += min(query(0, i), query(i + 1, n));
        update(i, -1);
    }
    cout << moves << '\n';
    
    return 0;
}