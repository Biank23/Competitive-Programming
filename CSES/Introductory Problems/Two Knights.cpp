#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll s = 1LL * i * i;
        ll j = 2LL * (i - 1) - 1;
        cout << s * (s - 1) / 2 - j * j + 1 << '\n';
    }
    
    return 0;
}
