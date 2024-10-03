#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int b; cin >> b; a[i] -= b;
    }
    vector<int> pref[2], pat[2] = {{1, 0, -1, -1, 0, 1},
                                   {0, 1, 1, 0, -1, -1}};
    ll sum[2] = {0LL, 0LL};
    for (int k = 0; k < 2; k++) {
        vector<int> s(n);
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            s[i] = pat[k][j];
            sum[k] += s[i] * a[i];
            if (++j == 6) j = 0;
        }
        pref[k].resize(n + 1);
        pref[k][0] = 0LL;
        for (int i = 0; i < n; i++) {
            pref[k][i + 1] = pref[k][i] + s[i];
        }
    }
    auto getAnswer = [&]() {
        if (sum[0] == 0LL && sum[1] == 0LL) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    };
    getAnswer();
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        for (int k = 0; k < 2; k++) {
            sum[k] += 1LL * (pref[k][r] - pref[k][l]) * x;
        }
        getAnswer();
    }
    
    return 0;
}