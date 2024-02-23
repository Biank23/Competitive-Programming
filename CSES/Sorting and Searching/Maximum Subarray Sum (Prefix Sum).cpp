#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    ll minPref = 0, pref = 0;
    ll maxSubarray = -INF;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pref += x;
        maxSubarray = max(maxSubarray, pref - minPref);
        minPref = min(minPref, pref);
    }
    cout << maxSubarray << '\n';
    
    return 0;
}