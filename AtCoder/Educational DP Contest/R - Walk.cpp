#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using Mat = vector<vi>;

const int MOD = 1e9+7;

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

void add(int &x, int v) {
    x += v;
    if (x >= MOD) x -= MOD;
}

Mat operator*(const Mat &a, const Mat &b) {
    int n = sz(a);
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
    int n = sz(a);
    Mat res(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) res = res * a;
        a = a * a, k /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    ll k; 
    cin >> n >> k;
    
    Mat a(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    a = binpow(a, k);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            add(res, a[i][j]);
        }
    }
    cout << res << '\n';
    
    return 0;
}
