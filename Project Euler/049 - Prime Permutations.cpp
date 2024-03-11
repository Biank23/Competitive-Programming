#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1e4;
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

    auto isPermutation = [](int a, int b) {
        string A = to_string(a);
        string B = to_string(b);
        sort(all(A)), sort(all(B));
        return A == B;
    };

    string res;
    for (int a = 1000; a < N; a++) {
        if (!p[a]) continue;
        for (int step = 1; a + 2 * step < N; step++) {
            int b = a + step, c = a + 2 * step;
            if (!p[b] || !p[c]) continue;
            if (isPermutation(b, a) && isPermutation(c, a)) {
                res = to_string(a) + to_string(b) + to_string(c);
            }
        }
    }
    cout << res << '\n';

    return 0;
}