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
 
const int SZ = 6;
 
Mat mul(const Mat &a, const Mat &b) {
	Mat c(SZ, vi(SZ, 0));
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            for (int k = 0; k < SZ; k++) {
                add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
	return c;
}
 
Mat binpow(Mat a, ll k) {
    Mat res(SZ, vi(SZ, 0));
    for (int i = 0; i < SZ; i++) {
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
    
    ll n;
    cin >> n;
    
    Mat R(SZ, vi(SZ, 0));
    for (int i = 0; i < SZ; i++) {
        R[SZ - 1][i] = 1;
        if (i != SZ - 1) R[i][i + 1] = 1;
    }
    
    Mat res = binpow(R, n);
    cout << res[SZ - 1][SZ - 1] << '\n';
    
    return 0;
}