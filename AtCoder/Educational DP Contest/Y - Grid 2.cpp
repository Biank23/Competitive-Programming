#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
 
using ll = long long;
using ii = pair<int, int>;

const int MAX_N = 2e5 + 5;
const int MOD = 1e9 + 7;

int fact[MAX_N], inv[MAX_N];
 
int mul(int a, int b) {
    return int(1LL * a * b % MOD);
}
 
int binpow(int a, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a), k /= 2;
    }
    return res;
}
 
void initFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    inv[MAX_N - 1] = binpow(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 1; i > 0; i--) {
        inv[i - 1] = mul(inv[i], i);
    }
}

int paths(int h, int w) {
    int n = h + w - 2, k = h - 1;
    return mul(fact[n], mul(inv[k], inv[n - k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int h, w, n;
    cin >> h >> w >> n;
    
    vector<ii> walls(n);
    for (auto &[r, c] : walls) {
        cin >> r >> c;
    }
    walls.emplace_back(h, w);
    sort(all(walls));

    vector<int> dp(n + 1);
    initFactorials();
    for (int i = 0; i <= n; i++) {
        auto [r, c] = walls[i];
        dp[i] = paths(r, c);
        for (int j = 0; j < i; j++) { //x <= r
            auto [x, y] = walls[j];
            if (y <= c) {
                dp[i] -= mul(dp[j], paths(r - x + 1, c - y + 1));
                if (dp[i] < 0) dp[i] += MOD;
            }
        }
    }
    cout << dp[n] << '\n';
    
    return 0;
}
