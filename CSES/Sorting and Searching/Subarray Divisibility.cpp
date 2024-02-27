#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> count(n, 0);
    ll pref = 0, cant = 0;
    for (int i = 0; i < n; i++) {
        count[pref]++;
        pref = (pref + v[i]) % n;
        if (pref < 0) pref += n;
        cant += count[pref];
    }
    cout << cant << '\n';
    
    
    return 0;
}