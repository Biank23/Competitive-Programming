#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;
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
    
    string s;
    cin >> s;
    int n = sz(s);
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (s[i] == '1');
    }
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i <= n; i++) {
        a[pref[i]]++;
        b[n - pref[i]]++;
    }
    vector<cd> fa(all(a)), fb(all(b));
    int m = 1 << (32 - __builtin_clz(sz(a) + sz(b)));
    fa.resize(m, 0), fb.resize(m, 0);
    fft(fa, false), fft(fb, false);
    for (int i = 0; i < m; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    vector<ll> ans(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ans[i] = (ll) round(fa[n + i].real());
        sum += ans[i];
    }
    ans[0] = n * (n + 1LL) / 2 - sum;
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    
    return 0;
}
