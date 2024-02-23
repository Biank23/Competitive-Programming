#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll x, y;
        cin >> x >> y;
        ll maxi = max(x, y), mini = min(x, y);
        ll res = (maxi - 1) * (maxi - 1);
        if (maxi % 2 == (x > y)) {
            res += mini;
        } else {
            res += 2 * maxi - mini;
        }
        cout << res << '\n';
    }
    
    return 0;
}
