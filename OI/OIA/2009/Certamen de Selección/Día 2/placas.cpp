#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 16, INF = 1e9;

int cost[1 << MAX_N], dp[1 << MAX_N];

int main() {
	freopen("placas.in", "r", stdin);
	freopen("placas.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> k >> n;
	
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
	
	for (int mask = 1; mask < 1 << n; mask++) {
        int minX = INF, minY = INF,
			maxX = -INF, maxY = -INF;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                minX = min(minX,x[i]), minY = min(minY,y[i]);
                maxX = max(maxX,x[i]), maxY = max(maxY,y[i]);
            }
        }
        dp[mask] = cost[mask] = 2 * (maxX - minX + maxY - minY + 4 * k);
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            dp[mask] = min(dp[mask], dp[mask ^ submask] + cost[submask]);
        }
    }
	
	cout << dp[(1<<n) - 1] << '\n';
		
	return 0;
}
