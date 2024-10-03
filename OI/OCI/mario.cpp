#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int SZ = 1<<17;

int st[2 * SZ], n;

void update(int i) {
    i += SZ;
    if (st[i]) {
        st[i] = 0, n--;
        while (i /= 2) {
            st[i] = st[2 * i] + st[2 * i + 1];
        }
    }
}

int search(int x){
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

int query(int l, int r) {
    int ans = 0;
    for (l += SZ, r += SZ; l < r; l /= 2, r /= 2) {
        if (l & 1) ans += st[l++];
        if (r & 1) ans += st[--r];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k[2];
    cin >> n >> k[0] >> k[1];
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st[i + SZ] = 1;
    }
    for (int i = SZ - 1; i > 0; i--) {
        st[i] = st[2 * i] + st[2 * i + 1];
    }
    int j[2] = {0, n - 1}, p[2] = {1, 1};
    bool dir[2] = {1, 0};
    ll points[2] = {0LL, 0LL};
    while (n > 1) {
        for (int i = 0; i < 2; i++) {
            if (((p[i] + k[i] - 1) / (n - 1)) & 1) {
                dir[i] = !dir[i];
            }
            p[i] = (p[i] + k[i] - 1) % (n - 1);
            j[i] = dir[i] ? search(p[i] + 1) : search(n - p[i]);
            points[i] += a[j[i]];
        }
        for (int i = 0; i < 2; i++) {
            update(j[i]);
        }
        for (int i = 0; i < 2; i++) {
            p[i] = query(0, j[i] + 1);
            if (!dir[i]) p[i] = n - p[i];
        }
    }
    if (points[0] >= points[1]) {
        cout<<"Mario\n";
    } else {
        cout<<"Bowser\n";
    }
    
    return 0;
}