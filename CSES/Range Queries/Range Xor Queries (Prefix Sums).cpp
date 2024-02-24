#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] ^= p[i-1];
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int res = p[r] ^ p[l - 1];
        cout << res << '\n';
    }
    
    return 0;
}