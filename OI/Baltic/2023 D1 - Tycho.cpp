#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(x.size())
 
using ll = long long;
 
const ll INF = 2e18;
 
struct STree {
    int n;
    vector<ll> st;
    STree(int _n) : n(_n), st(2 * n, INF) {}
    void update(int p, ll v) {
        p += n;
        st[p] = v;
        while (p /= 2) {
            st[p] = min(st[2 * p], st[2 * p + 1]);
        }
    }
    ll query(int l, int r){
        ll res = INF;
        for (l += n, r += n; l < r; l /= 2,r /= 2){
            if (l & 1) res = min(res, st[l++]);
            if (r & 1) res = min(st[--r], res);
        }
        return res;
    }
};
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll b, p;
    int n, d;
    cin >> b >> p >> d >> n;
    n++;
    vector<ll> a(n), vals(n);
    vals[0] = a[0] = 0LL;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        vals[i] = a[i] % p;
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    
    vector<ll> dp(n, INF);
    int c = sz(vals);
    STree st(c);
    st.update(0, dp[0] = 0);
    for (int i = 1; i < n; i++) {
        int m = int(lower_bound(all(vals), a[i] % p) - begin(vals));
        ll val = min(st.query(0, m) + p, st.query(m, c) - d);
        st.update(m, val);
        dp[i] = (a[i] / p) * (d + p) + val;
    }
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ll diff = b - a[i];
        ans = min(ans, dp[i] + ((diff - 1) / p) * d + diff);
    }
    cout << ans << '\n'; 
    
    return 0;
}
