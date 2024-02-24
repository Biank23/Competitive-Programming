#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAX_H = 19;
const int MAX_N = 1<<MAX_H;
 
ll sum[MAX_H][MAX_N];
int a[MAX_N];
 
void init(int l = 0, int r = MAX_N, int h = 0) {
    if (r - l < 2) return;
    int m = (l + r) / 2;
    sum[h][m - 1] = a[m - 1];
    for (int i = m - 2; i >= l; i--) {
        sum[h][i] = sum[h][i + 1] + a[i];
    }
    sum[h][m] = a[m];
    for (int i = m + 1; i < r; i++) {
        sum[h][i] = sum[h][i - 1] + a[i];
    }
    init(l, m, h + 1);
    init(m, r, h + 1);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init();
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int h = MAX_H + __builtin_clz(l ^ r) - 32;
        if (l == r) {
            cout << a[l] << '\n';
        } else {
            cout << sum[h][l] + sum[h][r] << '\n';
        }
    }
    
    return 0;
}