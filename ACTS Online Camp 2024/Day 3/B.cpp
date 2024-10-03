#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll ans[3] = {0, 0, 0};
        for (int i = 59; i >= 0; i--) {
            if (3LL << i <= n) {
                for (int j = 0; j < 3; j++) {
                    ans[j] += 1LL << i;
                    n -= 1LL << i;
                }
            } else {
                int j = 0;
                while (j < 3 && n > 3LL * ((1LL << i) - 1LL)) {
                    ans[j++] += 1LL << i;
                    n -= 1LL << i;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}