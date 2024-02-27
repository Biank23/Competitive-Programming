#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    ll p;
    cin >> n >> p;
    
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    auto check = [&](ll t) {
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            tot += t / k[i];
            if (tot >= p) {
                return true;
            }
        }
        return false;
    };
    
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
    
    
    return 0;
}