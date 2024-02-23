#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 2e5;
const ll INF = 1e18;
 
int x[MAX_N];
 
ll maxSubarraySum(int l, int r) {
    if (l > r) return -INF;
    int m = (l + r) / 2;
    ll suff = 0, left = 0;
    for (int i = m - 1; i >= l; i--) {
        suff += x[i];
        left = max(left, suff);
    }
    ll pref = 0, right = 0;
    for (int i = m + 1; i <= r; i++) {
        pref += x[i];
        right = max(right, pref);
    }
    ll best = left + x[m] + right;
    return max({maxSubarraySum(l, m - 1), maxSubarraySum(m + 1, r), best});
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << maxSubarraySum(0, n - 1) << '\n';
    
    return 0;
}