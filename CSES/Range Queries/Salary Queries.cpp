#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 4e5 + 9;
 
int ft[MAX_N];
 
inline int lsb(int i) {
    return i & (-i);
}
 
void update(int i, int v) {
    while (i < MAX_N) {
        ft[i] += v;
        i += lsb(i);
    }
}
 
int query(int i) {
    int s = 0;
    while (i > 0) {
        s += ft[i];
        i -= lsb(i);
    }
    return s;
}
 
int query(int l, int r) {
    return query(r) - query(l);
}
 
#define all(x) begin(x), end(x)
 
using Query = tuple<bool, int, int>;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<int> vals(all(p));
    vector<Query> v(q);
    for (auto &[type, a, b] : v) {
        char c;
        cin >> c >> a >> b;
        --a, type = (c == '!');
        if (type) vals.push_back(b);
    }
    
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    auto compress = [&](int x) {
        return int(upper_bound(all(vals), x) - begin(vals));
    };
    
    for (int i = 0; i < n; i++) {
        update(compress(p[i]), 1);
    }
    
    for (auto [type, a, b] : v) {
        if (type) {
            update(compress(p[a]), -1);
            p[a] = b;
            update(compress(p[a]), 1);
        } else {
            cout << query(compress(a), compress(b)) << '\n';
        }
    }
    
    return 0;
}
