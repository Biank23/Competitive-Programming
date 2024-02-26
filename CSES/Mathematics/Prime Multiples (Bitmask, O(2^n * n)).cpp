#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_K = 20;
 
ll a[MAX_K];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }    
    
    ll res = 0;
    for (int mask = 1; mask < 1<<k; mask++) {
        bool parity = 0;
        ll multiples = n;
        for (int i = 0; i < k; i++) {
            if (mask>>i&1) {
                multiples /= a[i];
                parity ^= 1;
            }
        }
        if (parity) res += multiples;
        else res -= multiples;
    }
    cout << res << '\n';
    
    return 0;
}