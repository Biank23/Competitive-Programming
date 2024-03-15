#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l = n, r = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 1) {
                count++;
                r = max(r, i);
                l = min(l, i);
            }
        }
        cout << (r - l + 1) - count << '\n'; 
    }
    
    return 0;
}