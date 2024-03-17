#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 1<<18;
 
int st[2*SZ];
 
void update(int p, int x) {
    for (st[p += SZ] -= x; p /= 2;) {
        st[p] = max(st[2 * p], st[2 * p + 1]);
    }
}
 
int search(int x) {
    int u = 1;
    if (st[u] < x) return -1;
    while (u < SZ) {
        u *= 2;
        if (st[u] < x) u++;
    }
    return u - SZ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
 
    for (int i = 0; i < n; i++) {
        cin >> st[i+SZ];
    }
    for (int i = SZ - 1; i > 0; i--) {
        st[i] = max(st[2 * i], st[2 * i + 1]);
    }
 
    while (q--) {
        int x;
        cin >> x;
        int p = search(x);
        if (p != -1) update(p, x);
        cout << p + 1 << ' ';
    }
 
    return 0;
}
