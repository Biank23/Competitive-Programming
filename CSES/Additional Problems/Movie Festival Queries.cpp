#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_A = 1e6 + 20;
const int MAX_K = 18;
 
int up[MAX_K][MAX_A];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for (int a = 0; a < MAX_A; a++) {
        up[0][a] = MAX_A - 1;
    }
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        up[0][a] = min(up[0][a], b);
    }
    
    for (int a = MAX_A - 2; a >= 0; a--) {
        up[0][a] = min(up[0][a], up[0][a + 1]);
    }
    
    for (int k = 1; k < MAX_K; k++) {
        for (int a = 0; a < MAX_A; a++) {
            up[k][a] = up[k - 1][up[k - 1][a]];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int res = 0;
        for (int k = MAX_K - 1; k >= 0; k--) {
            if (up[k][a] <= b) {
                res += 1<<k;
                a = up[k][a];
            }
        }
        cout << res << '\n';
    }
    
    return 0;
}