#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 9;
const int MAX_K = 18;
 
using ll = long long;
 
int up[MAX_K][MAX_N], x[MAX_N];
ll operations[MAX_K][MAX_N], pref[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        pref[i + 1] = pref[i] + x[i];
    }
    
    auto calc = [&](int l, int r) { //[l, r) where l is the max element
        return 1LL * (r - l) * x[l] - (pref[r] - pref[l]);
    };
    
    for (int i = n - 1; i >= 0; i--) {
        int j = i + 1;
        while (j < n && x[j] <= x[i]) {
            j = up[0][j];
        }
        up[0][i] = j;
        operations[0][i] = calc(i, j);
    }
    
    for (int i = 0; i < MAX_K; i++) {
        up[i][n] = n;
    }
    
    for (int i = 1; i < MAX_K; i++) {
        for (int j = 0; j < n; j++) {
            int k = up[i - 1][j];
            up[i][j] = up[i - 1][k];
            operations[i][j] = operations[i - 1][j] + operations[i - 1][k];
        }
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        ll res = 0;
        for (int i = MAX_K - 1; i >= 0; i--) {
            if (up[i][l] < r) {
                res += operations[i][l];
                l = up[i][l];
            }
        }
        res += calc(l, r);
        cout << res << '\n';
    }
    
    return 0;
}