#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int points = 0;
        for (int i = 0; i < 10; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 10; j++) {
                if (s[j] == 'X') points += min({i + 1, j + 1, 10 - i, 10 - j});
            }
        }
        cout << points << '\n';
    }
    
    return 0;
}
