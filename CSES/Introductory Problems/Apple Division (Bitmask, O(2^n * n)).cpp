#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    } 
    
    ll minDiff = INF;
    for (int mask = 0; mask < 1<<n; mask++) {
        ll sum[2] = {0, 0};
        for (int i = 0; i < n; i++) {
            sum[mask>>i&1] += p[i];
        }
        minDiff = min(minDiff, abs(sum[0] - sum[1]));
    }
    cout << minDiff << '\n';
    
    return 0;
}
