#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

const int N = 101;

ll grid[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> grid[i][j];
            grid[i][j] += max(grid[i - 1][j], grid[i - 1][j - 1]);
        }
    }
    cout << *max_element(all(grid[N - 1])) << '\n';

    return 0;
}