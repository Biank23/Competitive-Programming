#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 1<<18;
 
int st[2 * SZ];
 
void update(int p) {
    p += SZ;
    while (p) {
        --st[p];
        p /= 2;
    }
}
 
int search(int x) {
    int u = 1;
    while (u < SZ) {
        u *= 2;
        if (st[u] < x) {
            x -= st[u];
            u++;
        }
    }
    return u - SZ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
 
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        st[i + SZ] = 1;
    }
    for (int i = SZ - 1; i > 0; i--) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int p = search(x);
        update(p);
        cout << v[p] << ' ';
    }
 
    return 0;
}