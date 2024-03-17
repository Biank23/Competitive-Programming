#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> c(2, 0);
        long long ans = (m + 1LL) * (m + 2LL) / 2LL;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans -= x / 2 + 1;
            ans -= m - x + 1;
            c[x % 2]++;
        }
        for (int &x : c) {
            ans += x * (x + 1LL) / 2LL;
        }
        cout << ans << '\n';
    }
    
    return 0;
}