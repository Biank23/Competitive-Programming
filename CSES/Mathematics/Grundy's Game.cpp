#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1300;
 
int mex(set<int> &s) {
    for (int i = 0; i < MAX_N; i++) {
        if (!s.count(i)) return i;
	}
	assert(false);
}
 
int dp[MAX_N];
 
void init() {
    for (int i = 0; i < MAX_N; i++) {
        set<int> s;
        for (int j = 1; j < (i + 1) / 2; j++) {
            s.insert(dp[j] ^ dp[i - j]);
        }
        dp[i] = mex(s);
    }
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	init();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
        if (n >= MAX_N || dp[n] != 0) {
            cout << "first\n";
        } else {
            cout << "second\n";
        }
	}
	
	return 0;
}