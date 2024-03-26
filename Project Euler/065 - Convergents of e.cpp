#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

struct BigInt : string {
    BigInt() : string() {}
    BigInt(int a, char c) : string(a, c) {}
    BigInt(int x) : string(to_string(x)) {}
    BigInt& operator++() {
        int i = (int) size() - 1;
        while (i >= 0 && at(i) == '9') {
            at(i) = '0';
            i--;
        }
        if (i != -1) ++at(i);
        else insert(0, "1");
        return *this;
    }
    friend BigInt operator+(BigInt a, BigInt b) {
        reverse(all(a));
        reverse(all(b));
        int n = max(sz(a), sz(b));
        a.insert(sz(a), BigInt(n - sz(a), '0'));
        b.insert(sz(b), BigInt(n - sz(b), '0'));
        BigInt c(n + 1, '0');
        for (int i = 0; i < n; i++) {
            int sum = (a[i] - '0') + (b[i] - '0') + (c[i] - '0');
            c[i + 1] += char(sum / 10);
            c[i] = char('0' + sum % 10);
        }
        while (sz(c) > 1 && c.back() == '0') {
            c.pop_back();
        }
        reverse(all(c));
        return c;
    }
    BigInt& operator+=(const BigInt &o) {
        return *this = *this + o;
    }
    friend BigInt operator*(BigInt a, BigInt b) {
        reverse(all(a)), reverse(all(b));
        BigInt c(sz(a) + sz(b), '0');
        for (int i = 0; i < sz(a); i++) {
            for (int j = 0; j < sz(b); j++) {
                int prod = (a[i] - '0') * (b[j] - '0') + (c[i + j] - '0');
                c[i + j + 1] += prod / 10;
                c[i + j] = '0' + prod % 10;
            }
        }
        while (sz(c) > 1 && c.back() == '0') {
            c.pop_back();
        }
        reverse(all(c));
        return c;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    const int N = 100;
    
    vector<BigInt> v{2, 1, 2};
    for (BigInt k = 2; sz(v) < N; ++k) {
        v.push_back(1);
        v.push_back(1);
        v.push_back(2 * k);
    }
    while (sz(v) > N) v.pop_back();
    BigInt num = 1, den = 0;
    reverse(all(v));
    for (BigInt a : v) {
        tie(num, den) = make_pair(num * a + den, num);
    }
    BigInt ans = 0;
    for (char digit : num) {
        ans += digit - '0';
    }
    cout << ans << '\n';
    
    return 0;
}
