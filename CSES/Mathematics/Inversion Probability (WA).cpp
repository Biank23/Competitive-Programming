// gives WA in TC 13#
// expected "485.035848"
// found "485.035849"
// someone make a TC where
// the answer is so close to (n + 0.5) / 10^6
// where n is a possitive integer
// then, rounding with C++ gives WA
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    
    double res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int tot = r[i] * r[j], fav;
            if (r[j] < r[i]) {
                fav = r[j] * (r[j] - 1) / 2;
            } else {
                fav = r[i] * (r[i] - 1) / 2 + r[i] * (r[j] - r[i]);
            }
            res += (double) fav / tot;
        }
    }
    cout << fixed << setprecision(6) << res << '\n';
    
    return 0;
}
