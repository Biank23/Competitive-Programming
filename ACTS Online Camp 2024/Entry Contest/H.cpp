#include <bits/stdc++.h>

using namespace std;

#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define forn(i, n) for(int i = 0;i < int(n); i++)

const int MAXN = 260;

int a[MAXN][MAXN][MAXN];

int query(int i0, int j0, int k0, int i1, int j1, int k1) {
    i1++, j1++, k1++;
    return a[i1][j1][k1]
            - a[i0][j1][k1] - a[i1][j0][k1] - a[i1][j1][k0]
            + a[i0][j0][k1] + a[i0][j1][k0] + a[i1][j0][k0]
            - a[i0][j0][k0];
}

using iii = tuple<int,int,int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,m; cin >> n >> m;
    vi r(n), g(n), b(n);
    forn(i, n){
        cin >> r[i] >> g[i] >> b[i];
        a[r[i]+1][g[i]+1][b[i]+1]++;
    }
    forsn(i, 1, MAXN) forsn(j, 1, MAXN) forsn(k, 1, MAXN) {
        a[i][j][k] += a[i-1][j][k] + a[i][j-1][k] + a[i][j][k-1]
                     - a[i-1][j-1][k] - a[i-1][j][k-1] - a[i][j-1][k-1]
                     + a[i-1][j-1][k-1];
    }
    iii ans = {0, 0, 0};
    auto check = [&](int d) {
        forn(i, MAXN - d - 1) forn(j, MAXN - d - 1) forn(k, MAXN - d - 1) {
            if (query(i, j, k, i + d, j + d, k + d) >= m) {
                ans = {i, j, k};
                return true;
            }
        }
        return false;
    };
    int lo = -1, hi = MAXN;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    auto [i, j, k] = ans;
    int d = hi, count = 0;
    forn(p, n) {
        if(r[p] >= i && r[p] <= i + d &&
           g[p] >= j && g[p] <= j + d &&
           b[p] >= k && b[p] <= k + d){
               cout << p + 1 << ' ';
               if (++count == m) break;
        }
    }
    
    return 0;
}