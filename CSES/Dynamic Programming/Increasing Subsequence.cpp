#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(lis), x[i]);
        if (it == lis.end()) {
            lis.push_back(x[i]);
        } else {
            *it = x[i];
        }
    }
    cout << ssize(lis) << '\n';
    
    return 0;
}