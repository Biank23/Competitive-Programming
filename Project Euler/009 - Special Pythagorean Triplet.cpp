#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 1000;
    //find the solutions of
    //a + b + c = N
    //a^2 + b^2 = c^2
    for (int a = 1; a < N; a++) {
        for (int b = a; a + b < N; b++) {
            int c = N - a - b;
            if (a * a + b * b == c * c) {
                cout << 1LL * a * b * c << '\n';
            }
        }
    }

    return 0;
}