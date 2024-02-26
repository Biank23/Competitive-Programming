#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 9;
const int MAX_K = 100;
 
bitset<MAX_N> dp;
int p[MAX_K];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i >= p[j] && !dp[i - p[j]]) {
                dp[i] = true;
            }
        }
        if (dp[i]) cout << 'W';
        else cout << 'L';
    }
    cout << '\n';
    
    return 0;
}