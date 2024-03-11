#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

bool check(int x) {
    string num = to_string(x);
    sort(all(num));
    for (int i = 2; i <= 6; i++) {
        string multiple = to_string(i * x);
        sort(all(multiple));
        if (num != multiple) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 6 * x has the same number of digits of x
    // => the first digit of x is 1
    // => 2 * x start with 2, 3 * x start with 3...
    // => x has >= 6 digits
    bool found = false;
    for (int pot = 1e5; !found; pot *= 10) {
        // 3 * x is multiple of 3
        // x has the same digits that 3 * x
        // => x is multiple of 3
        for (int i = 2; i < pot; i += 3) {
            if (check(pot + i)) {
                cout << pot + i << '\n';
                found = true;
                break;
            }
        }
    }

    return 0;
}