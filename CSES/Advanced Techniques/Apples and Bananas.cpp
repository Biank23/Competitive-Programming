#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using cd = complex<double>;
const double PI = acos(-1);

int reverse(int num, int log) {
    int res = 0;
    for (int i = 0; i < log; i++) {
        if (num >> i & 1) res |= 1 << (log - 1 - i);
    }
    return res;
}

void fft(vector<cd> &a, bool invert) {
    int n = sz(a);
    int log = 31 - __builtin_clz(n);
    for (int i = 0; i < n; i++) {
        int j = reverse(i, log);
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len *= 2) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a) x /= n;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int k, n[2];
    cin >> k >> n[0] >> n[1];
    vector<int> c[2];
    for (int i = 0; i < 2; i++) {
        c[i].assign(k + 1, 0);
        for (int j = 0; j < n[i]; j++) {
            int w;
            cin >> w;
            c[i][w]++;
        }
    }
    vector<cd> a(all(c[0])), b(all(c[1]));
    int s = 1 << (32 - __builtin_clz(sz(a) + sz(b)));
    a.resize(s, 0), b.resize(s, 0);
    fft(a, false), fft(b, false);
    for (int i = 0; i < s; i++) {
        a[i] *= b[i];
    }
    fft(a, true);
    for (int i = 2; i <= 2 * k; i++) {
        cout << (long long) round(a[i].real()) << ' ';
    }
    
    return 0;
}
