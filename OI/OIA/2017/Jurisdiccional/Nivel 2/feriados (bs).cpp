#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, d, f;
    cin >> n >> d >> f;
    
    vector<int> c(d + 1, 1);
    c[0] = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a] = 0;
    }
    for (int i = 1; i <= d; i++) {
        c[i] += c[i - 1];
    }
    
    auto check = [&](int k) {
        for (int i = 0; i <= d - k; i++) {
            if (c[i + k] - c[i] <= f) return true;
        }
        return false;
    };
    
    int l = 0, r = d + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    
    cout << l << '\n';
    
    return 0;
}
