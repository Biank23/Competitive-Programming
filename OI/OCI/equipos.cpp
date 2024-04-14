#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_TOT = 100 * 99 * 100 + 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << "0\n1\n";
        for (int i = 2; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    }
    
    vector<int> v(n);
    int tot = 0;
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        tot += k, v[i - 1] += k, v[j - 1] += k;
    }
    
    vector<bitset<MAX_TOT>> dp(n + 1);
    dp[0][2 * tot] = true;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] | (dp[i] >> v[i]);
    }
    
    pair<int, int> res = {INF, -1};
    for (int i = 0; i <= 2 * tot; i++) {
        if (dp[n][i]) res = min(res, {abs(i - tot), i});
    }
        
    cout << res.first << '\n';
    int j = res.second;
    vector<int> otro_equipo;
    for (int i = n - 1; i >= 0; i--) {
        if (j + v[i] >= MAX_TOT || !dp[i][j + v[i]]) {
            otro_equipo.push_back(i);
        } else {
            j += v[i];
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
    
    for (int i : otro_equipo) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}
