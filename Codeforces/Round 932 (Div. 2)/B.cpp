#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using vi = vector<int>;

vi get(vi a) {
    int n = sz(a);
    set<int> s;
    for (int i = 0; i <= n; i++) {
        s.insert(i);
    }
    vi pref(n);
    for (int i = 0; i < n; i++) {
        s.erase(a[i]);
        pref[i] = *s.begin();
    }
    return pref;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vi pref = get(a);
        reverse(all(a));
        vi suff = get(a);
        reverse(all(suff));
        bool found = false;
        for (int i = 1; i < n && !found; i++) {
            if (pref[i - 1] == suff[i]) {
                cout << "2\n";
                cout << "1 " << i << '\n';
                cout << i + 1 << ' ' << n << '\n';
                found = true;
            }
        }
        if (!found) {
            cout << "-1\n";
        }
    }
    
    return 0;
}
