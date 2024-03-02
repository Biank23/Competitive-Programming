#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_D = 19;
using ll = long long;
 
ll pot[MAX_D];
void init() {
    pot[0] = 1LL;
    for (int i = 1; i < MAX_D; i++) {
        pot[i] = pot[i - 1] * 10LL;
    }
}
 
ll count(ll x) {
    ll res = 0;
    for (int i = 1; i < MAX_D; i++) {
        if (pot[i - 1] > x) break;
        ll digit = (x % pot[i]) / pot[i - 1];
        res += (x / pot[i]) * pot[i - 1];
        if (digit == 1) res += (x % pot[i]) - (pot[i - 1] - 1);
        else if (digit != 0) res += pot[i - 1];
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    
    init();
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (count(m) <= n) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
    
    return 0;
}