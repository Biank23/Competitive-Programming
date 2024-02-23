#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 1<<19;
 
int st[2 * SZ];
 
void init(int n) {
    for (int i = 0; i < n; i++) {
        st[i + SZ] = 1;
    }
    for (int i = SZ - 1; i > 0; i--) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
}
 
int find(int sum) {
    int u = 1;
    while (u < SZ) {
        u *= 2;
        if (st[u] < sum) {
            sum -= st[u];
            u++;
        }
    }
    return u - SZ;
}
 
void update(int u) {
    --st[u += SZ];
    while (u /= 2) {
        st[u] = st[2 * u] + st[2 * u + 1]; 
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    init(n);
    int position = 0;
    for (int children = n; children > 0; children--) {
        position += k;
        position %= children;
        int child = find(position + 1);
        cout << child + 1 << ' ';
        update(child);
    }
    cout << '\n';
    
    return 0;
}