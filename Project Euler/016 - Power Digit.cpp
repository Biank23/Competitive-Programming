#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1000;
    auto sum = [&](string a, string b) {
        reverse(all(a));
        reverse(all(b));
        int n = max(sz(a), sz(b));
        a += string(n - sz(a), '0');
        b += string(n - sz(b), '0');
        string c(n + 1, '0');
        for (int i = 0; i < n; i++) {
            int s = (a[i] - '0') + (b[i] - '0') + (c[i] - '0');
            c[i] = s % 10 + '0';
            c[i + 1] += s / 10;
        }
        while (sz(c) > 1 && c.back() == '0') {
            c.pop_back();
        }
        reverse(all(c));
        return c;
    };
    string pot = "1";
    for (int i = 0; i < N; i++) {
        pot = sum(pot, pot);
    }
    ll res = 0;
    for (char digit : pot) {
        res += digit - '0';
    }
    cout << res << '\n';

    return 0;
}