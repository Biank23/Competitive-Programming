#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
typedef vector<int> vi;
using ll = long long;
const int MAX_N = 2e5+10;
 
inline int lsb(int i) {
    return i & -i;
}
 
struct FTree {
    ll ft[MAX_N];
    void update(int i, ll v) {
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
};
 
FTree ft1, ft2;
 
void update(int l, int r, ll v) {
    ft1.update(l, v);
    ft1.update(r, -v);
    ft2.update(l, v * (l - 1));
    ft2.update(r, -v * (r - 1));
}
 
ll query(int i) {
    return ft1.query(i) * (i - 1) - ft2.query(i);
}
 
int main() {
    int n, q;
    cin >> n >> q;
    
    forn(i,n) {
        int a; cin >> a;
        update(i, i + 1, a);
    }
    
    forn(i,q) {
        int t; cin >> t;
        if(t==1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(a - 1, b, u);
        } else {
            int k;
            cin >> k;
            cout << query(k) - query(k - 1) << '\n';
        }
    }
 
    return 0;
}