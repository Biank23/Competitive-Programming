#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        string s;
        cin >> s;
        s += "#";
        int n = sz(s);
        int ans = 0, mini = n, count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                count++, ans++;
            } else {
                mini = min(mini, count);
                count = 0;
            }
        }
        ans -= mini;
        cout << ans << '\n';
    }
    
    return 0;
}
