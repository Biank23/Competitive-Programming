#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

const int MAX_N = 4e4 + 9;
const int MAX_K = 305;
const int INF = 1e9;

int dp[MAX_N][MAX_K];

int main() {
    freopen("vuelo.in", "r", stdin);
	freopen("vuelo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < MAX_K; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < MAX_K; j++) {
            int cost = abs(a - j);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost);
            if (j + 1 < MAX_K) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + cost);
        }
    }
    int ans = INF;
    int pos = -1;
    for (int j = 0; j < MAX_K; j++) {
        if (dp[n][j] < ans) {
            ans = dp[n][j];
            pos = j;
        }
    }
    cout << ans << '\n';
    vector<int> path;
    int i = n - 1;
    while (pos != 0) {
        path.push_back(pos);
        if (pos == 0 || dp[i][pos + 1] < dp[i][pos - 1]) {
            pos++;
        } else {
            pos--;
        }
        i--;
    }
    reverse(all(path));
    for (int h : path) {
        cout << h << '\n';
    }
    return 0;
}
