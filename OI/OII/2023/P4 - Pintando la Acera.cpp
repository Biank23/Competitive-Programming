#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX_N = 309;

struct Range {
    int l, r, c;
};

Range ran[MAX_N];

int dp[MAX_N][MAX_N], par[MAX_N][MAX_N];
int c[MAX_N];
vector<Range> ans;

int buildRanges(int n) {
    int idx = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || c[i] != c[i + 1]) {
            ran[idx] = {j, i, c[i]};
            idx++, j = i + 1;
        }
    }
    return idx;
}

void solve(int l, int r) {
    if (l > r) return;
    int i = par[l][r];
    Range paint = {ran[l].l, ran[i].r, ran[l].c};
    ans.push_back(paint);
    bool flag = ran[i + 1].c == ran[r + 1].c;
    solve(l + 1, i - 1);
    solve(i + 1 + flag, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int S = buildRanges(n);
    for (int l = S - 1; l >= 0; l--) {
        for (int r = l; r < S; r++) {
            dp[l][r] = INF;
            for (int i = l; i <= r; i++) {
                if (ran[i].c != ran[l].c) continue;
                bool flag = ran[i + 1].c == ran[r + 1].c;
                int curr = 1 + dp[l + 1][i - 1] + dp[i + 1 + flag][r];
                if (curr < dp[l][r]) dp[l][r] = curr, par[l][r] = i;
            }
        }
    }
    cout << dp[0][S - 1] << '\n';
    solve(0, S - 1);
    for (auto [l, r, k] : ans) {
        cout << l + 1 << ' ' << r + 1 << ' ' << k << '\n';
    }
    
    return 0;
}