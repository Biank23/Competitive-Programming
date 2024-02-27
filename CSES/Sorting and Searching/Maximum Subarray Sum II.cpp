#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<ll> p(n + 1);
    p[0] = 0;
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + v[i];
    }
    
    int k = b - a + 1;
    multiset<ll> s;
    ll res = -INF;
    for (int i = 0; i <= n - a; i++) {
        s.insert(p[i]);
        if (i >= k) {
            s.erase(s.find(p[i - k]));
        }
        res = max(res, p[i + a] - *begin(s));
    }
    cout << res << '\n';
    
    return 0;
}