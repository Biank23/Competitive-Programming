#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
const int MAX_K = 18;
 
int up[MAX_K][MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 2; i <= n; i++) {
        cin >> up[0][i];
    }
    
    for (int i = 0; i < MAX_K - 1; i++) {
        for (int j = 1; j <= n; j++) {
            up[i + 1][j] = up[i][up[i][j]];
        }
    }
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < MAX_K; i++) {
            if (k>>i&1) x = up[i][x];
        }
        if (x == 0) x = -1;
        cout << x << '\n';
    }
    
    
    return 0;
}