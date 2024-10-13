#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];
    
    vector<int> cnt(26, 0);
    for (int i = 0; i < 7; i++) {
        char c; cin >> c;
        cnt[c - 'A']++;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> copy = cnt;
        bool flag = true;
        for (char c : dict[i]) {
            if (--copy[c - 'A'] < 0) flag = false;
        }
        if (flag) ans = max(ans, sz(dict[i]));
    }
    if (ans > 3) cout << 2 * ans << '\n';
    else cout << ans << '\n';
    
    return 0;
}