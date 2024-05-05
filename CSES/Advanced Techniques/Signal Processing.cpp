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
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    reverse(all(b));
    vector<cd> fa(all(a)), fb(all(b));
    int s = 1 << (32 - __builtin_clz(sz(a) + sz(b)));
    fa.resize(s, 0), fb.resize(s, 0);
    fft(fa, false), fft(fb, false);
    for (int i = 0; i < s; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    for (int i = 0; i < n + m - 1; i++) {
        cout << (int) round(fa[i].real()) << ' ';
    }
    
    return 0;
}
