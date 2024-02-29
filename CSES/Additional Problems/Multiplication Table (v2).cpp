#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    
    ll target = (n * n + 1) / 2;
    
    auto check = [&](ll x) {
        ll count = 0, j = n;
        for (int i = 1; i <= n; i++) {
            while (i * j > x) j--;
            count += j;
        }
        return count >= target;
    };
    
    ll l = 0, r = n * n;
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