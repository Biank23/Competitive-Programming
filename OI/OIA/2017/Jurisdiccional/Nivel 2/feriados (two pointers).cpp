#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, d, f;
    cin >> n >> d >> f;
    
    vector<bool> c(d, true);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a - 1] = false;
    }
    
    int l = 0, sum = 0, ans = 0;
    for (int r = 0; r < d; r++) {
        sum += c[r];
        while (sum >  f) {
            sum -= c[l++];
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    
    return 0;
}
