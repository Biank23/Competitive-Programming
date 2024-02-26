#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9+7;
 
using ll = long long;
using vi = vector<int>;
using Mat = vector<vi>;
 
int mul(int a, int b) {
    return int(1LL * a * b % MOD); 
}
 
void add(int &x, int v) {
    x += v;
    if (x >= MOD) x -= MOD;
}
 
int n;
 
Mat mul(const Mat &a, const Mat &b) {
	Mat c(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
	return c;
}
 
Mat binpow(Mat a, ll k) {
    Mat res(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
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
    
    Mat adj(n, vi(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1][v - 1]++;
    }
    
    Mat res = binpow(adj, k);
    cout << res[0][n - 1] << '\n';
    
    return 0;
}