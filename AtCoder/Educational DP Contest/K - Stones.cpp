#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<bool> dp(k + 1, false);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; !dp[i] && j < n; j++) {
            if (i >= a[j] && !dp[i - a[j]]) {
                dp[i] = true;
            }
        }
    }
	
	if (dp[k]) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    
    return 0;
}
