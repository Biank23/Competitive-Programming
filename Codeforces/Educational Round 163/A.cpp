#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string ans = "";
        for (int i = 0; i < n / 2; i++) {
            ans += string(2, char('A' + i % 2));
        }
        cout << ans << '\n';
    }
    
    return 0;
}
