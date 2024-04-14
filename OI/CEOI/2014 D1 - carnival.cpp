#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define pb push_back
 
using vi = vector<int>;
 
int query(vi &a) {
    if (sz(a) <= 1) {
        return sz(a);
    }
    cout << sz(a) << ' ';
    for (int i = 0; i < sz(a); i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    int C;
    cin >> C;
    return C;
}
 
int main() {
    int n; cin >> n;
    int prev = 0;
    vi c, pref, ans(n);
    for (int i = 0; i < n; i++) {
        pref.pb(i);
        int curr = query(pref);
        if (curr != prev) {
            c.pb(i + 1);
            ans[i] = sz(c);
        } else {
            int l = 0, r = sz(c);
            while (l + 1 < r) {
                int m = (l + r) / 2;
                vi q(c.begin(), c.begin() + m);
                q.pb(i + 1);
                if (query(q) == m) {
                    r = m;
                } else {
                    l = m;
                }
            }
            ans[i] = r;
        }
        prev = curr;
    }
    
    cout << "0 ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
