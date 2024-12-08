#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int x = 0;
        if (n % 2 == 0) {
            x = n / 2;
        } else if (n % 4 == 3) {
            x = (n + 1) / 4;
        } else {
            assert(n % 4 == 1);
            for (int d = 3; d * d <= n + 4; d += 4) {
                if (n % d == 0 || (n + 4) % d == 0) {
                    x = (n + d) / 4;
                    break;
                }
            }
        }
        if (x) cout << x << ' ' << n * (x + 1LL) / (4LL * x - n) << '\n';
        else cout << "0\n";
    }

    return 0;
}