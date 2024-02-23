#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    int maxi = 0;
    ll moves = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < maxi) {
            moves += maxi - x;
        } else {
            maxi = x;
        }
    }
    cout << moves << '\n';
    
    return 0;
}
