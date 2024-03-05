#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 100;
    auto multiply = [&](string a, string b) {
        reverse(all(a)), reverse(all(b));
        string c(sz(a) + sz(b), '0');
        for (int i = 0; i < sz(a); i++) {
            for (int j = 0; j < sz(b); j++) {
                int prod = (a[i] - '0') * (b[j] - '0') + (c[i + j] - '0');
                c[i + j + 1] += prod / 10;
                c[i + j] = (prod % 10) + '0';
            }
        }
        while (sz(c) > 1 && c.back() == '0') {
            c.pop_back();
        }
        reverse(all(c));
        return c;
    };

    string fac = "1";
    for (int i = 1; i <= N; i++) {
        fac = multiply(fac, to_string(i));
    }
    ll sum = 0;
    for (char digit : fac) {
        sum += digit - '0';
    }
    cout << sum << '\n';

    return 0;
}