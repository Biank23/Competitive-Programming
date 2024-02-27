#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    map<ll, int> m;
    ll pref = 0, cant = 0;
    for (int i = 0; i < n; i++) {
        m[pref]++;
        pref += v[i];
        cant += m[pref - x];
    }
    cout << cant << '\n';
    
    return 0;
}