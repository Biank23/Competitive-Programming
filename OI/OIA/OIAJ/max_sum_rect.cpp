#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int kadane(vector<int> &v) {
    int curr = -INF, best = -INF;
    for (int &x : v) {
        curr = max(curr + x, x);
        best = max(best, curr);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n + 1, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i + 1][j];
            mat[i + 1][j] += mat[i][j];
        }
    }
    int ans = -INF;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r <= n; r++) {
            vector<int> v(m);
            for (int i = 0; i < m; i++) {
                v[i] = mat[r][i] - mat[l][i];
            }
            ans = max(ans, kadane(v));
        }
    }
    cout << ans << '\n';
    
    return 0;
}
