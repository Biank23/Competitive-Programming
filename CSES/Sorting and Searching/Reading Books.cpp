#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    int maxi = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        maxi = max(maxi, t);
        sum += t;
    }
    
    cout << max(sum, 2LL * maxi) << '\n';
    
    return 0;
}