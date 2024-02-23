#include <bits/stdc++.h>
 
using namespace std;
 
void solve(int n, int x, int y) {
    if (n == 0) return;
    int z = 6 - x - y;
    solve(n - 1, x, z);
    cout << x << ' ' << y << '\n';
    solve(n - 1, z, y);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    cout << (1<<n) - 1 << '\n';
    solve(n, 1, 3);
    
    return 0;
}
