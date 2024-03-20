#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        int n;
        cin >> n;
        vector<int> L(n);
        for (int i = 0; i < n; i++) {
            cin >> L[i];
        }
        int cost = 0;
        for (int i = 0; i < n - 1; i++) {
            int j = int(min_element(begin(L) + i, end(L)) - begin(L));
            cost += j - i + 1;
            reverse(begin(L) + i, begin(L) + j + 1);
        }
        cout << "Case #" << tt << ": " << cost << '\n';
    }
    
    return 0;
}
