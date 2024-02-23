#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    int zeros = 0;
    for (int d = 5; d <= n; d *= 5) {
        zeros += n / d;
    }
    cout << zeros << '\n';
    
    return 0;
}
