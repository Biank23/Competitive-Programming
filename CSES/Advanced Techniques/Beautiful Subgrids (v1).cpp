#include <bits/stdc++.h>
#pragma GCC target("popcnt")
 
using namespace std;
 
using ll = long long;
 
const int MAX_N = 3000;
 
bitset<MAX_N> grid[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int c = (grid[i] & grid[j]).count();
            res += c * (c - 1) / 2;
        }
    }
    cout << res << '\n';
    
    return 0;
}