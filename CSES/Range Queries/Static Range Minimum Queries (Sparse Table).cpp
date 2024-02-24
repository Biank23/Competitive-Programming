#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5+9;
const int MAX_K = 19;
 
int st[MAX_K][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> st[0][i];
    }
    
    for (int i = 0; i < MAX_K - 1; i++) {
        for (int j = 0; j < n-(1<<i); j++) {
            st[i + 1][j] = min(st[i][j], st[i][j + (1<<i)]);
        }
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        int i = 31 - __builtin_clz(r - l);
        cout << min(st[i][l], st[i][r - (1<<i)]) << '\n';
    }
    
    return 0;
}