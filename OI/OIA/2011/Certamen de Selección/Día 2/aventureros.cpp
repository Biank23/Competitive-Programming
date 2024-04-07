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
    for (st[u += SZ]--; u /= 2;) {
        st[u] = st[2 * u] + st[2 * u + 1]; 
    }
}
 
int main() {
    freopen("aventureros.in", "r", stdin);
    freopen("aventureros.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    init(n);
    vector<int> k(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> k[i];
    }
    int pos = 0, cant = n;
    for (int i = 0; i < n - 1; i++) {
        pos += k[i];
        pos %= cant;
        int j = find(pos + 1);
        cout << j + 1 << ' ';
        update(j), cant--;
    }
    int j = find(1);
    cout << '\n' << j + 1 << '\n';
    
    return 0;
}
