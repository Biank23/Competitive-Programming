#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<bool> r(n, false), c(n, false),
                d1(2 * n - 1, false), d2(2 * n - 1, false);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        r[x] = c[y] = d1[x + y] = d2[n - 1 + y - x] = true;
    }
    for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
        if (!r[x] && !c[y] && !d1[x + y] && !d2[n - 1 + y - x]) count++;
    }
    cout << count << '\n';
    
    return 0;
}