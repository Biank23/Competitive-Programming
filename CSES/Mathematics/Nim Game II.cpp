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
        int x = 0;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            x ^= v&3; //v % 4
        }
        if (x == 0) {
            cout << "second\n";
        } else {
            cout << "first\n";
        }
    }
    
    return 0;
}