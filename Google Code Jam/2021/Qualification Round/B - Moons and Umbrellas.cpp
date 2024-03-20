#include <bits/stdc++.h>

using namespace std;

#define sz(x) int(x.size())

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        int n = sz(s);
        vector<int> dp[2];
        for (int i = 0; i < 2; i++) {
            dp[i].assign(n, INF);
        }
        int cost[2] = {y, x};
        const string forbidden = "JC";
        auto put = [&](int i, int j, int val) {
            if (s[i] != forbidden[j]) dp[j][i] = val;
        };
        put(0, 0, 0), put(0, 1, 0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                put(i, j, min(dp[j][i - 1], dp[1 - j][i - 1] + cost[j]));
            }
        }
        cout << "Case #" << tt << ": " << min(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
    
    return 0;
}
