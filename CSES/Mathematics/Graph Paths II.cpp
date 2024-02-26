#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vll = vector<ll>;
using Mat = vector<vll>;
 
const ll INF = 2e18;
int n;
 
Mat mul(const Mat &a, const Mat &b) {
    Mat c(n, vll(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return c;
}
 
Mat binpow(Mat a, ll k) {
    Mat res(n, vll(n, INF));
    for (int i = 0; i < n; i++) {
        res[i][i] = 0;
    }
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, k;
    cin >> n >> m >> k;
    
    Mat adj(n, vll(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u][v] = min(adj[u][v], ll(w));
    }
    
    Mat res = binpow(adj, k);
    if (res[0][n - 1] == INF) res[0][n - 1] = -1;
    cout << res[0][n - 1] << '\n';
    
    return 0;
}
