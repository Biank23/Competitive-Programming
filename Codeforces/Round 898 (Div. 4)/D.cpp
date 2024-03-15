#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int op = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') op++, i += k - 1;
        }
        cout << op << '\n';
    }
    
    return 0;
}
