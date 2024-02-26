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
 
const int SZ = 2;
 
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
    Mat res = {{1, 0}, {0, 1}};
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}
 
ll fib(ll n) {
    if (n == 0) return 0;
    Mat res = binpow(Mat{{1, 1}, {1, 0}}, n - 1);
    return res[0][0];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    cout << fib(n) << '\n';
    
    return 0;
}