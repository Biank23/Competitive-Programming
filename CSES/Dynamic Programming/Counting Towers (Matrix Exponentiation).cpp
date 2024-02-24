#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 9;
const int MOD = 1e9 + 7;
 
using ll = long long;
 
struct ModInt {
    int val;
    ModInt(int v = 0) : val(v) {}
    ModInt& operator+=(ModInt o) {
        val += o.val;
        if (val >= MOD) {
            val -= MOD;
        }
        return *this;
    }
    ModInt& operator*=(ModInt o) {
        val = int((ll) val * o.val % MOD);
        return *this;
    }
    friend ModInt operator+(ModInt x, ModInt y) {
        return x += y;
    }
    friend ModInt operator*(ModInt x, ModInt y) {
        return x *= y;
    }
    friend ostream& operator<<(ostream &os, ModInt x) {
        return os << x.val;
    }
    bool operator!=(ModInt o) {
        return val != o.val;
    }
}; 
 
using Mat = vector<vector<ModInt>>;
const Mat BASE = {{2, 1}, {1, 4}};
const Mat ID = {{1, 0}, {0, 1}};
 
Mat operator*(Mat a, Mat b) {
   int m = ssize(a);
   int p = ssize(b[0]);
   int n = ssize(b);
   assert(n == ssize(a[0]));
   Mat c = Mat(m, vector<ModInt>(p, 0));
   for (int i = 0; i < m; i++) {
       for (int j = 0; j < p; j++) {
           for (int k = 0; k < n; k++) {
               c[i][j] += a[i][k] * b[k][j];
           }
       }
   }
   return c;
}
 
Mat binpow(Mat a, int k) {
    Mat res = ID;
    while (k > 0) {
        if (k % 2 == 1) {
            res = res * a;
        }
        a = a * a, k /= 2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 0; tt < TT; tt++) {
        int n;
        cin >> n;
        Mat res = Mat{{1,1}} * binpow(BASE, n - 1);
        cout << res[0][0] + res[0][1] << '\n';
    }
    
    return 0;
}