#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> v(n);
    for (int p = 0; p < 2; p++) {
        int j = n - 1;
        if (j % 2 == p) j--;
        for (int i = p; i < n; i += 2) {
            while (j >= 0 && a[i] + a[j] > x) j -= 2;
            v[i] = (i + j) / 2;
        }
    }
    
    int k = 32 - __builtin_clz(n);
    vector<vector<int>> st(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        st[0][i] = v[i];
    }
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < n - (1 << i); j++) {
            st[i + 1][j] = min(st[i][j], st[i][j + (1 << i)]);
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        bool flag = true;
        if ((r - l) % 2 == 0) {
            flag = a[r] <= x;
            r--;
        }
        int m = (l + r) / 2;
        int log = 31 - __builtin_clz(m - l + 1);
        int res = min(st[log][l], st[log][m + 1 - (1 << log)]);
        flag &= res >= m;
        cout << flag;
    }
    
    return 0;
}