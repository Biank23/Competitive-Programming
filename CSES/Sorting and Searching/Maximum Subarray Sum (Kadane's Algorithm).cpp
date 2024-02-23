#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    ll curr = -INF, maxi = -INF;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        curr = max(curr + x, x);
        maxi = max(maxi, curr);
    }
    cout << maxi << '\n';
    
    return 0;
}