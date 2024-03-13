#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1 ; tt <= TT; tt++) {
        int R, C, A, B;
        cin >> R >> C >> A >> B;
        cout << "Case #" << tt << ": ";
        if (R > C) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
}
