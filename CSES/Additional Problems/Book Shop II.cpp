#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;
const int MAX_X = 1e5 + 9;

int price[MAX_N], pages[MAX_N], cant[MAX_N];
int dp[MAX_X];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
	    cin >> price[i];
	}
	for (int i = 0; i < n; i++) {
	    cin >> pages[i];
	}
	for (int i = 0; i < n; i++) {
	    cin >> cant[i];
	}
	
	auto process = [&](int h, int s) {
	    for (int i = x; i >= h; i--) {
	        dp[i] = max(dp[i], dp[i - h] + s);
	    }
	};
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; cant[i] >= 1<<j; j++) {
	        process(price[i]<<j,
	                pages[i]<<j);
	        cant[i] -= 1<<j;
	    }
	    if (cant[i] > 0) {
	        process(price[i] * cant[i],
	                pages[i] * cant[i]);
	    }
	}
	
	cout << dp[x] << '\n';
}