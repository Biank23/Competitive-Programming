#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        auto check = [&](ll h) {
            ll water = 0;
            for (int i = 0; i < n; i++) {
                water += max(0LL, h - a[i]);
                if (water > x) return false;
            }
            return true;
        };
        
        ll low = 1, high = 2e9 + 10;
        while (low + 1 < high) {
            ll mid = (low + high) / 2;
            if (check(mid)) low = mid;
            else high = mid;
        }
        cout << low << '\n';
    }
    
    return 0;
}
