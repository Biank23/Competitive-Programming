#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> towers;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        auto it = upper_bound(all(towers), size);
        if (it == towers.end()) {
            towers.push_back(size);
        } else {
            *it = size;
        }
    }
    cout << ssize(towers) << '\n';
    
    return 0;
}