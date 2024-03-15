#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = sz(s);
        int ans = 0;
        for (int k = 1; 2 * k <= n; k++) {
            int count = 0;
            bool flag = false;
            auto check = [&](int i) {
                return s[i] == s[i + k] || s[i] == '?' || s[i + k] == '?';
            };
            for (int i = 0; i < n - k; i++) {
                count += check(i);
                if (i >= k) count -= check(i - k);
                if (count == k) flag = true;
            }
            if (flag) ans = 2 * k;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
