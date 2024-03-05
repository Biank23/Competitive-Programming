#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 20;
    auto valid = [&](int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    };
    int grid[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    const int MOVES = 4;
    const int dx[MOVES] = {0, 1, 1, 1};
    const int dy[MOVES] = {1, 0, 1, -1};

    const int K = 4;
    auto prod = [&](int x, int y, int d) {
        ll p = 1;
        for (int i = 0; i < K; i++) {
            if (!valid(x, y)) return 0LL;
            p *= grid[x][y];
            x += dx[d], y += dy[d];
        }
        return p;
    };
    ll res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < MOVES; k++) {
                res = max(res, prod(i, j, k));
            }
        }
    }
    cout << res << '\n';

    return 0;
}