#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto isPandigital = [](string num) {
        sort(all(num));
        return num == "123456789";
    };

    ll res = 0;
    const int ub = sqrt(987654321);
    for (int i = 1; i <= ub; i++) {
        string num = "";
        int n = 1;
        while (sz(num) < 9) {
            num += to_string(i * n);
            n++;
        }
        if (isPandigital(num)) {
            res = max(res, stoll(num));
        }
    }
    cout << res << '\n';

    return 0;
}