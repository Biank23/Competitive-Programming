#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    auto check = [&](ll m) {
        ll sum = 0;
        int d = 1;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            if (sum > m) {
                d++;
                sum = v[i];
                if (sum > m || d > k) {
                    return false;
                }
            }
        }
        return true;
    };
    
    ll l = 0, r = 2e14;
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