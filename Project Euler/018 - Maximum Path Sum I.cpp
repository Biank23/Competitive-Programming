#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;

const int N = 15;

int grid[N][N];

//note: it can be improved (see 067 - Maximum Path Sum II)
ll path(int x, int y) {
    if (x == N) return 0;
    if (x < y) return -INF;
    return grid[x][y] + max(path(x + 1, y), path(x + 1, y + 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> grid[i][j];
        }
    }
    cout << path(0, 0) << '\n';

    return 0;
}