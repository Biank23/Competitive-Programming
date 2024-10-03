#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)

typedef long long ll;

const int MAXN = 21;

ll p[MAXN][MAXN][MAXN], memo[1 << MAXN];

ll dp(int mask) {
    if (mask == 0) return 0LL;
    ll &ans = memo[mask];
    if (ans != -1) return ans;
    int a = __builtin_ctz(mask);
    for(int i = mask ^ (1 << a); i > 0; i -= i & -i) {
        int b = __builtin_ctz(i);
        for (int j = i ^ (1 << b); j > 0; j -= j & -j) {
            int c = __builtin_ctz(j);
            ans=max(ans, dp(mask ^ (1 << a) ^ (1 << b) ^ (1 << c)) + p[a][b][c]);
        }
    }
    return ans;
}

ll c[MAXN][MAXN], a[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    forn(i,n) forn(j,n) {
        cin >> c[i][j];
    }
    forn(i,n) cin >> a[i];
    forn(i,n) forn(j,n) forn(k,n){
        p[i][j][k] = max({a[i], a[j], a[k],
                    c[i][j], c[j][k], c[k][i],
                    c[i][j] * c[j][k] * c[k][i]});
    }
    memset(memo, -1, sizeof memo);
    cout << dp((1 << n) - 1) << '\n';
    
    return 0;
}