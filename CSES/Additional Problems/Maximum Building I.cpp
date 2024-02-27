#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    vector<int> v(n, 0);
    ll res = 0;
    for (int j = 0; j < m; j++) {
        string s;
        cin >> s;
        
        for (int i = 0; i < n; i++) {
            ++v[i];
            if (s[i] == '*') v[i] = 0;
        }
    
        vector<int> l(n);
        for (int i = 0; i < n; i++) {
            l[i] = i - 1;
            while (l[i] != -1 && v[l[i]] >= v[i]) {
                l[i] = l[l[i]];
            }
        }
    
        vector<int> r(n);
        for (int i = n - 1; i >= 0; i--) {
            r[i] = i + 1;
            while (r[i] != n && v[r[i]] >= v[i]) {
                r[i] = r[r[i]];
            }
        }
        
        for (int i = 0; i < n; i++) {
            res = max(res, (r[i] - l[i] - 1LL) * v[i]);
        }
    }
    
    cout << res << '\n';
    
    return 0;
}