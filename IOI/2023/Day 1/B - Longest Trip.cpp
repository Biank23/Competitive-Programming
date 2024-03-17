#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(x.size())
#define pb push_back

using vi = vector<int>;
bool are_connected(vi A, vi B);

const int MAX_N = 256;
int c[MAX_N][MAX_N], n;

bool query(int x, int y) {
    if (c[x][y] == 1) {
        return true;
    }
    if (c[x][y] == 0) {
        return false;
    }
    for (int z = 0; z < n; z++) {
        if (z == x || z == y) continue;
        if (c[x][z] == 0 && c[y][z] == 0) {
            c[x][y] = c[y][x] = 1;
            return true;
        }
    }
    c[x][y] = c[y][x] = are_connected({x}, {y});
    return c[x][y]; 
}

int bs(vi a, vi b) {
    int l = 0, r = sz(a);
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (are_connected(b, vi(begin(a) + m, begin(a) + r))) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

vi longest_trip(int N, int /*D*/) {
    n = N;
    memset(c, -1, sizeof c);
    vi P(n);
    for (int i = 0; i < n; i++) {
        P[i] = i;
    }
    srand(time(0));
    random_shuffle(all(P));
    vi a={P[0]}, b;
    for (int i = 1; i < n; i++) {
        if (query(a.back(), P[i])) {
            a.pb(P[i]);
        } else if(!b.empty() && query(a.back(),b.back())) {
            for (int j = sz(b) - 1; j >= 0; j--) {
                a.pb(b[j]);
            }
            b = {P[i]};
        } else if (b.empty() || query(b.back(), P[i])) {
            b.pb(P[i]);
        }
    }
    if (sz(b) > sz(a)) swap(a, b);
    if (b.empty() || !are_connected(a, b)) {
        return a;
    }
    for (int i = 0; i < 2; i++) {
        if (query(a.back(), b.front())) {
            for (int j = 0; j < sz(b); j++) {
                a.pb(b[j]);
            }
            return a;
        }
        swap(a, b);
    }
    for (int i = 0; i < 2; i++) {
        if (query(a.back(), b.back())) {
            for (int j = sz(b) - 1; j >= 0; j--) {
                a.pb(b[j]);
            }
            return a;
        }
        reverse(all(a)), reverse(all(b));
    }
    
    int i = bs(a,b);
    int j = bs(b,{a[i]});
    
    vi ans;
    for (int p = j + 1; p < sz(b); p++) {
        ans.pb(b[p]);
    }
    for (int p = 0; p <= j; p++) {
        ans.pb(b[p]);
    }
    for (int p = i; p < sz(a); p++) {
        ans.pb(a[p]);
    }
    for (int p = 0; p < i; p++) {
        ans.pb(a[p]);
    }
    return ans;
}
