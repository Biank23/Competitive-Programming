#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5, MAX_K = 30;
 
int up[MAX_K][MAX_N];
 
void init(int n) {
    for (int i = 1; i < MAX_K; i++) {
        for (int j = 0; j < n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
}
 
int jump(int x, int k) {
    for (int i = 0; i < MAX_K; i++) {
        if (k>>i&1) x = up[i][x];
    }
    return x;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    for (int i = 0; i < n; i++) {
        cin >> up[0][i];
        --up[0][i];
    }
    init(n);
    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;
        cout << jump(x, k) + 1 << '\n';
    }
 
    return 0;
}