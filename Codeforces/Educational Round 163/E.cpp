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
        int q = 0;
        vector<int> a(n), c(n);
        for (int l = 0; l < n; l += k) {
            q++;
            int r = min(l + k, n);
            for (int i = l; i < r; i++) {
                c[i] = q;
            }
            int m = (l + r) / 2;
            int val = l;
            for (int i = m; i < r; i++) {
                a[i] = ++val;
            }
            val = r;
            for (int i = m - 1; i >= l; i--) {
                a[i] = val--;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n' << q << '\n';
        for (int i = 0; i < n; i++) {
            cout << c[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
