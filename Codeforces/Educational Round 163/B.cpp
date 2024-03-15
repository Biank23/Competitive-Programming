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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool possible = true;
        int lastNum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < lastNum) {
                possible = false;
                break;
            }
            bool canSplit = true;
            int lastDigit = lastNum;
            string num = to_string(a[i]);
            for (char digit : num) {
                if (digit - '0' < lastDigit) {
                    canSplit = false;
                    break;
                }
                lastDigit = digit - '0';
            }
            if (canSplit) lastNum = lastDigit;
            else lastNum = a[i];
        }
        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
