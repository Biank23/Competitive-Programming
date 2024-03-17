#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define fst first
#define snd second

const int INF = 1e9;
const int MAX_N = 1001;

int n;
int grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

pair<int, string> solve(auto val) {
    for (int i = 0; i <= n; i++) {
        dp[0][i] = dp[i][0] = INF;
    }
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + val(grid[i][j]);
        }
    }
    string path = "";
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (dp[i - 1][j] < dp[i][j - 1]) {
            path += 'D';
            i--;
        } else {
            path += 'R';
            j--;
        }
    }
    path.pop_back();
    reverse(all(path));
    return {dp[n][n], path};
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    
    auto zeros = solve([](int v){return v == 0 ? -1 : 0;});
    zeros.fst = zeros.fst == 0 ? INF : 1;
    
    auto getPow = [](int d) {
        return [&](int v) {
            if (v == 0) return INF;
            int c = 0;
            while (v % d == 0) {
                v /= d, c++;
            }
            return c;
        };
    };
    
    auto ans = min({solve(getPow(2)), solve(getPow(5)), zeros});
    cout << ans.fst << '\n';
    cout << ans.snd << '\n';
    
    return 0;
}
