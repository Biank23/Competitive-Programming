#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1e6;
    bool p[N];
    for (int i = 2; i < N; i++) {
        p[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        if (!p[i]) continue;
        for (int j = i * i; j < N; j += i) {
            p[j] = false;
        }
    }

    auto check = [&](int n) {
        for (int i = 1; 2 * i * i < n; i++) {
            if (p[n - 2 * i * i]) return true;
        }
        return false;
    };

    for (int i = 9; i < N; i += 2 /*odd numbers*/) {
        if (!p[i]/*composite*/ && !check(i)) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}