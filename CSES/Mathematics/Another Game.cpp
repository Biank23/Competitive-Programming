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
        bool flag = false;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            if (v % 2 == 1) {
                flag = true;
            }
        }
        if (flag) {
            cout << "first\n";
        } else {
            cout << "second\n";
        }
    }
    
    return 0;
}