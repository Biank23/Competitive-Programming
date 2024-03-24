#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int s = 1, t = 1;
        while (t < n) { //s <= t
            s += t;
            t += s;
        }
        if (s < n) {
            cout << s << '\n';
        } else {
            cout << "OK\n";
        }
    }
    
    return 0;
}
