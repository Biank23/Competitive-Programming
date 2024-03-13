#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1 ; tt <= TT; tt++) {
        int S, D, K;
        cin >> S >> D >> K;
        cout << "Case #" << tt << ": ";
        if (S + 2 * D >= K && 2 * S + 2 * D >= K + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
}