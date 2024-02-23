//Time Complexity: O(n)
//Space Complexity: O(1)
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        x ^= i;
    }
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        x ^= a;
    }
    cout << x << '\n';
    
    return 0;
}
