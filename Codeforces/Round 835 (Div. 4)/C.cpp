#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int j = int(max_element(all(a)) - begin(a));
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (i != j) maxi = max(maxi, a[i]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = a[i] - a[j];
        }
        ans[j] = a[j] - maxi;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
