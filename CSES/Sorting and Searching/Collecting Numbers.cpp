#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        --x[i];
        idx[x[i]] = i;
    }
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (idx[i] < idx[i - 1]) rounds++;
    }
    cout << rounds << '\n';
    
    return 0;
}