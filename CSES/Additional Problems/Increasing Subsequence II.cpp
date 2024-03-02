#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
 
const int MAX_N = 2e5 + 9;
const int MOD = 1e9 + 7;
 
int ft[MAX_N];
 
inline int lsb(int i) {
    return i & (-i);
}
 
void update(int i, int v) {
    ++i;
    while (i < MAX_N) {
        ft[i] += v;
        if (ft[i] >= MOD) {
            ft[i] -= MOD;
        }
        i += lsb(i);
    }
}
 
int query(int i) { //[0, i)
    int s = 0;
    while (i > 0) {
        s += ft[i];
        if (s >= MOD) {
            s -= MOD;
        }
        i -= lsb(i);
    }
    return s;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), vals(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        vals[i] = x[i];
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    
    for (int i = 0; i < n; i++) {
        int pos = int(lower_bound(all(vals), x[i]) - begin(vals));
        int curr = query(pos) + 1;
        update(pos, curr);
    }
    cout << query(n) << '\n';
    
    return 0;
}