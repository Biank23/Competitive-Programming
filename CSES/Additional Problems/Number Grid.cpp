#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int x, y;
    cin >> x >> y;
    int res = (x - 1) ^ (y - 1);
    cout << res << '\n';
    
    return 0;
}
