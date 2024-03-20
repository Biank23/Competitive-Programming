#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        int n, c;
        cin >> n >> c;
        if (c < n - 1 || c > n * (n + 1) / 2 - 1) {
            cout << "Case #" << tt << ": IMPOSSIBLE\n";
            continue;
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        vector<int> L(n);
        for (int i = 0; i < n - 1; i++) {
            int target = c - (n - i - 2);
            int cost = min(target, n - i);
            int j = i + cost - 1;
            reverse(begin(p) + i, begin(p) + j + 1);
            L[p[i]] = i + 1;
            c -= cost;
        }
        L[p[n - 1]] = n;
        cout << "Case #" << tt << ":";
        for (int i = 0; i < n; i++) {
            cout << ' ' << L[i];
        }
        cout << '\n';
    }
    
    return 0;
}
