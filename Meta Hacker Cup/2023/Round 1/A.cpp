#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1 ; tt <= TT; tt++) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        sort(all(x));
        int v = (end(x)[-1] + end(x)[-2]) - (x[0] + x[1]);
        if (n == 5) {
            v = max((end(x)[-1] + end(x)[-2]) - (x[0] + x[2]),
                    (end(x)[-1] + end(x)[-3]) - (x[0] + x[1]));
        }
        string ans = to_string(v / 2);
        if (v % 2 == 1) ans += ".5";
        cout << "Case #" << tt << ": " << ans << '\n';
    }
    
    return 0;
}
