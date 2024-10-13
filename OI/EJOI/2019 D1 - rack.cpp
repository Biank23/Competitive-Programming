#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MOD = 1e9 + 7;
const int MAX_N = 1e6;
 
ll pot[MAX_N];
 
int solve(int n, ll k) {
    if (n == 0) return 1LL;
    if (k % 2 == 1) return solve(n - 1, (k + 1) / 2);
    int res = pot[n - 1] + solve(n - 1, k / 2);
    if (res >= MOD) res -= MOD;
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    ll k;
    cin >> n >> k;
    pot[0] = 1;
    for (int i = 1; i < n; i++) {
        pot[i] = 2 * pot[i - 1];
        if (pot[i] >= MOD) pot[i] -= MOD;
    }
    cout << solve(n, k) << '\n';
    
    return 0;
}