//Time Complexity: O(n)
//Space Complexity: O(n)
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<bool> missing(n + 1, true); 
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        missing[a] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (missing[i]) cout << i << '\n';
    }
    
    return 0;
}
