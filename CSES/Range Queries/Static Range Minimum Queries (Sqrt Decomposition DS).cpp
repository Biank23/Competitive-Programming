#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9+20;
const int MAX_N = 2e5+9;
const int BLOCK_SIZE = 450;
const int CANT_BLOCKS = MAX_N / BLOCK_SIZE + 1;
 
int b[MAX_N / BLOCK_SIZE + 1], a[MAX_N];
 
int query(int l, int r) {
    int x = l / BLOCK_SIZE;
    int y = r / BLOCK_SIZE;
    int res = INF;
    int maxi = min((x + 1) * BLOCK_SIZE, r + 1);
    for (int i = l; i < maxi; i++) {
        res = min(res, a[i]);
    }
    for (int i = x + 1; i < y; i++) {
        res = min(res, b[i]);
    }
    int mini = max(y * BLOCK_SIZE, l);
    for (int i = mini; i <= r; i++) {
        res = min(res, a[i]);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < CANT_BLOCKS; i++) {
        b[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int &block = b[i / BLOCK_SIZE];
        block = min(block, a[i]);
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r - 1) << '\n';
    }
    
    return 0;
}