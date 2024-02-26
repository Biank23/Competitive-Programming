#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 9;
const int MOD = 1e9 + 7;
 
int mul(int a, int b) {
    return int(1LL * a * b % MOD);
}
 
int subfact[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    subfact[0] = 1, subfact[1] = 0;
    for (int i = 2; i <= n; i++) {
        subfact[i] = mul(i - 1, subfact[i - 1] + subfact[i - 2]);
    }
    cout << subfact[n] << '\n';
    
    return 0;
}
