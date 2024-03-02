#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    ll k;
    cin >> n >> k;
    int l = 1, r = n;
    for (int i = n - 1; i >= 0; i--) {
        if (k >= i) {
            k -= i;
            cout << r << ' ';
            r--;
        } else {
            cout << l << ' ';
            l++;
        }
    }
    
    return 0;
}