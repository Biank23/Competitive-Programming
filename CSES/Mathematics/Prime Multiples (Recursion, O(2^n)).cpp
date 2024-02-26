#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_K = 20;
 
ll a[MAX_K], res = 0;
int k;
 
void solve(int i, int count, ll multiples) {
    if (multiples == 0) return;
    if (i == k) {
        if (count % 2 == 1) {
            res += multiples;
        } else if (count != 0) {
            res -= multiples;
        }
        return;
    }
    solve(i + 1, count, multiples);
    solve(i + 1, count + 1, multiples / a[i]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }    
    solve(0, 0, n);
    cout << res << '\n';
    
    return 0;
}