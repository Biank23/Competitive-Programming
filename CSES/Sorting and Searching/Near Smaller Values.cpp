#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        l[i] = i - 1;
        while (l[i] != -1 && v[l[i]] >= v[i]) {
            l[i] = l[l[i]];
        }
        cout << l[i] + 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}