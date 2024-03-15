#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> val(n);
        for (int i = 0; i < n; i++) {
            int pos;
            cin >> pos;
            int dist = abs(pos);
            val[dist - 1] += a[i];
        }
        
        ll bullets = k;
        bool flag = true;
        for (int dist = 0; dist < n && flag; dist++) {
            if (val[dist] > bullets) {
                flag = false;
            }
            bullets -= val[dist];
            bullets += k;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}