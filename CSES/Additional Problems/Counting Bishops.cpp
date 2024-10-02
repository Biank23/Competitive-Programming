#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
const int MOD = 1e9 + 7;
 
void add(int &a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}
 
int mul(int a, int b) {
    return int(1LL * a * b % MOD);
}
 
vector<int> solve(vector<int> sz, int k) {
    sort(all(sz));
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int s : sz) {
        for (int j = min(k - 1, s); j >= 0; j--) {
            add(dp[j + 1], mul(dp[j], s - j));
        }
    }
    return dp;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> freq(2 * n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            freq[i + j]++;
        }
    }
    vector<int> sz[2];
    for (int i = 0; i < 2 * n - 1; i++) {
        sz[i % 2].push_back(freq[i]);
    }
    vector<int> ways[2];
    for (int i = 0; i < 2; i++) {
        ways[i] = solve(sz[i], k);
    }
    
    int res = 0;
    for (int i = 0; i <= k; i++) {
        add(res, mul(ways[0][i], ways[1][k - i]));
    }
    cout << res << '\n';
    
    return 0;
}