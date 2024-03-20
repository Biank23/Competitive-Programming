#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        int n;
        cin >> n;
        map<int, ll> m;
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            int p;
            ll c;
            cin >> p >> c;
            m[p] = c;
            tot += p * c;
        }
        ll ans = 0;
        const int MAX_SUM = (int) min(60LL * 499LL, tot - 1);
        for (int sum = 0; sum < MAX_SUM; sum++) {
            ll targetProd = tot - sum;
            ll targetSum = sum;
            bool flag = true;
            for (auto &[p, c] : m) {
                int k = 0;
                while (targetProd % p == 0) {
                    targetProd /= p;
                    k++;
                }
                targetSum -= p * k;
                if (k > c || targetSum < 0) {
                    flag = false;
                    break;
                }
            }
            if (targetProd != 1 || targetSum != 0) flag = false;
            if (flag) {
                ans = tot - sum;
                break;
            }
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
    
    return 0;
}
