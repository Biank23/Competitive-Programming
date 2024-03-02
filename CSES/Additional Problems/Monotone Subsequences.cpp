#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k * k < n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (int i = n; i > 0; i -= k) {
            for (int j = max(1, i - k + 1); j <= i; j++) {
                cout << j << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
