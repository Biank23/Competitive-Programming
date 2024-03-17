#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_K = 801, MAX_N = 8001;

ll pref[MAX_N], dp[MAX_K][MAX_N];

ll cost(int l, int r) {
    return (r - l + 1) * (pref[r] - pref[l - 1]);
}

ll calc(int k, int l, int r) {
    if (l > r) swap(l, r);
    return cost(l, r) + dp[k - 1][r + 1];
}

void solve(int k, int l, int r, int optMin, int optMax) {
    if (l > r) return;
    int i = (l + r) / 2;
    int opt = optMin;
    for (int j = optMin + 1; j <= optMax; j++) {
        if (calc(k, j, i) < calc(k, opt, i)) opt = j;
    }
    dp[k][i] = calc(k, opt, i);
    solve(k, l, i - 1, optMin, opt);
    solve(k, i + 1, r, opt, optMax);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    if (k > n) k = n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pref[i + 1] = pref[i] + x;
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = cost(i, n);
    }

    for (int i = 1; i < k; i++) {
        solve(i, 1, n - i, 1, n - i);
    }

    cout << dp[k - 1][1] << endl;

    return 0;
}
