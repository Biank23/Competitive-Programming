#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1000;

    vector<int> count(N + 1, 0);
    for (int c = 1; c <= N / 2; c++) {
        for (int a = 1; a < c; a++) {
            int b = sqrt(c * c - a * a);
            if (a * a + b * b == c * c) {
                count[a + b + c]++;
            }
        }
    }

    int ans = max_element(all(count)) - begin(count);
    cout << ans << '\n';

    return 0;
}