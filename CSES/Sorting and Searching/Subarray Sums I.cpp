#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int sum = 0, l = 0, cant = 0;
    for (int r = 0; r < n; r++) {
        sum += v[r];
        while (sum > x) {
            sum -= v[l];
            ++l;
        }
        if (sum == x) {
            ++cant;
        }
    }
    cout << cant << '\n';
    
    return 0;
}