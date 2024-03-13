#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using vi = vector<int>;
using ii = pair<int, int>;

ii manacher(vi &s) {
    int n = sz(s);
    vector<vi> d(2, vi(n, 0));
    int l, r;
    for (int c : {0, 1}) {
        l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 1 - c : min(d[c][l + r - i + c], r - i + c);
            k += c;
            while (i + k - c < n && i >= k && s[i + k - c] == s[i - k]) {
                k++;
            }
            d[c][i] = c ? --k : k--;
            if (i + k - c > r) {
                l = i - k;
                r = i + k - c;
            }
        }
    }
    return {l, r};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        int n; cin >> n;
        
        vi a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        
        ii p = manacher(a);
        int ans = p.first / 2;
        
        vi v(2 * n);
        int pos = ans;
        for (int i = 0; i < 2 * n; i++) {
            v[i] = a[pos];
            if (++pos == 2 * n) pos = 0;
        }
            
        auto check = [&]() {
            for (int i = 0; i < n; i++) {
                if (v[i] != v[2 * n - i - 1]) return false;
                if (i < n / 2 && v[i] >= v[i + n]) return false;
                if (i > (n + 1) / 2 && v[i] <= v[i + n]) return false;
            }
            return true;
        };
            
        if (!check()) {
            for (int i = 0; i < n; i++) {
                swap(v[i], v[i + n]);
            }
            ans += n;
        }
        
        cout << "Case #" << tt << ": ";
        if (check()) cout << ans << '\n';
        else cout << "-1\n";
    }
    
    return 0;
}
