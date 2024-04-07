#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2009;

int p[MAX_N][MAX_N];
int f[MAX_N][MAX_N];

int query(int i, int j, int l, int a[MAX_N][MAX_N]) {
    return a[i + l][j + l] - a[i + l][j] - a[i][j + l] + a[i][j];
}

void init(int n, int m, int a[MAX_N][MAX_N]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
}

void read(int n, int a[MAX_N][MAX_N]) {
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y]++;
    }
}

int main() {
    freopen("frutales.in", "r", stdin);
	freopen("frutales.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, cp, cf;
    cin >> n >> m >> cp >> cf;
    read(cp, p), read(cf, f);
    init(n, m, p), init(n, m, f);
    int cant = -1, length = 0;
    pair<int, int> pos = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int low = 0;
            int high = min(n - i, m - j) + 1;
            while (low + 1 < high) {
                int mid = (low + high) / 2;
                if (query(i, j, mid, p) == 0) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            int target = query(i, j, low, f);
            if (cant > target) continue;
            high = low;
            low = 0;
            while (low + 1 < high) {
                int mid = (low + high) / 2;
                if (query(i, j, mid, f) == target) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            if (cant < target || (cant == target && length > high)) {
                cant = target;
                length = high;
                pos = {i, j};
            }
        }
    }
    auto [i, j] = pos;
    cout << i << ' ' << j << '\n';
    cout << length << '\n';
    cout << cant << '\n';
    
    return 0;
}
