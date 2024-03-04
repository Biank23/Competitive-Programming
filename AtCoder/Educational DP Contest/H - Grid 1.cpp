#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> dp(m, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			if (row[j] == '#') {
				dp[j] = 0;
			} else if (j > 0) {
				dp[j] += dp[j - 1];
				if (dp[j] >= MOD) dp[j] -= MOD;
			}
		}
	}
	
	cout << dp[m - 1] << '\n';
	
	return 0;
}