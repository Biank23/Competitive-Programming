#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

void add(int &x, int v) {
    x += v;
    if (x >= MOD) x -= MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    vector<vector<int>> c(K + 1, vector<int>(K + 1));
    for (int i = 0; i <= K; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            add(c[i][j], c[i - 1][j]);
            add(c[i][j], c[i - 1][j - 1]);
        }
    }
    vector<vector<int>> s(K + 1, vector<int>(30));
    for (int i = 0; i < 30; i++) s[0][i] = 1 << i;
    for (int k = 1; k <= K; k++) {
        s[k][0] = 1;
        for (int b = 1; b < 30; b++) {
            s[k][b] = s[k][b - 1];
            int a = 1 << (b - 1);
            int ai = 1;
            for (int i = 0; i <= k; i++) {
                add(s[k][b], mul(mul(c[k][i], ai), s[k - i][b - 1]));
                ai = mul(ai, a);
            }
        }
    }
    auto S = [&](int x, int k) {
        int r = 0;
        int a = 0;
        for (int b = 0; b < 30; b++) {
            if (!(x >> b & 1)) continue;
            int ai = 1;
            for (int i = 0; i <= k; i++) {
                add(r, mul(c[k][i], mul(ai, s[k - i][b])));
                ai = mul(ai, a);
            }
            a += 1 << b;
        }
        return r;
    };
    int l = 1;
    int ans = 0;
    while (l <= N) {
        int lo = l, hi = N + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (N / l == N / mid) lo = mid;
            else hi = mid;
        }
        int r = hi;
        int sum = S(r - 1, K) - S(l - 1, K);
        if (sum < 0) sum += MOD;
        add(ans, mul(N / l, sum));
        l = r;
    }
    cout << ans << '\n';
    
    return 0;
}