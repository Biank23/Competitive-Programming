#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1005;
 
int ft[MAX_N][MAX_N];
bool b[MAX_N][MAX_N];
 
inline int lsb(int i) {
    return i & (-i);
}
 
void update(int i0, int j0, int v) {
    for (int i = i0 + 1; i < MAX_N; i += lsb(i)) {
        for (int j = j0 + 1; j < MAX_N; j += lsb(j)) {
            ft[i][j] += v;
        }
    }
}
 
int get(int i0, int j0) {
    int res = 0;
    for (int i = i0; i > 0; i -= lsb(i)) {
        for (int j = j0; j > 0; j -= lsb(j)) {
            res += ft[i][j];
        }
    }
    return res;
}
 
int query(int i0, int j0, int i1, int j1) {
    return get(i1, j1) - get(i0, j1) - get(i1, j0) + get(i0, j0);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            b[i][j] = (s[j] == '*');
            if (b[i][j]) update(i, j, 1);
        }
    }
    
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;
        if (t == 1) {
            int val = b[x][y] ^ 1;
            update(x, y, val - b[x][y]);
            b[x][y] = val;
        } else {
            int x2, y2;
            cin >> x2 >> y2;
            cout << query(x, y, x2, y2) << '\n';
        }
    }
    
    return 0;
}
