#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int a[3];
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a, a + 3);
        cout << a[1] << '\n';
    }
    
    return 0;
}
