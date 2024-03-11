#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())
#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1e6;
    int f[N];
    for (int i = 2; i < N; i++) {
        if (f[i] != 0) continue;
        for (int j = i; j < N; j += i) {
            f[j]++;
        }
    }

    const int K = 4;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (f[i] == K) {
            count++;
        }
        if (i >= K && f[i - K] == K) {
            count--;
        }
        if (count == K) {
            cout << i - K + 1 << '\n';
            break;
        }
    }

    return 0;
}