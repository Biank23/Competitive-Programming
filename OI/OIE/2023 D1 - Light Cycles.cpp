#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, c, k;
        cin >> n >> m >> c >> k;
        vector<vector<int>> t(n, vector<int>(m, -k - 1));
        bool flag = true;
        for (int i = 0; i < c; i++) {
            int ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            t[ax][ay] = i;
            if (i - t[bx][by] <= k) flag = false;
        }
        if (flag) cout << "AZUL\n";
        else cout << "AMARILLO\n";
    }
    
    return 0;
}