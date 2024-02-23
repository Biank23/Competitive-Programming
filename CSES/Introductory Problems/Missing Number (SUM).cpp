//Time Complexity: O(n)
//Space Complexity: O(1)
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    ll tot = n * (n + 1LL) / 2;
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << tot - sum << '\n';
    
    return 0;
}
