#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n;
        string s;
        cin >> n >> s;
        int x = 0;
        for (char c : s) {
            x = max(x, c - 'a' + 1);
        }
        cout << x << '\n';
    }
    
    return 0;
}
