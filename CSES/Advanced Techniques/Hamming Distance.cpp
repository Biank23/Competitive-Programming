#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e4;
 
int a[MAX_N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < k; j++) {
            if (s[j] == '1') a[i] |= 1<<j;
        }
    }
    
    int res = 30;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            res = min(res, __builtin_popcount(a[i] ^ a[j]));
        }
    }
    cout << res << '\n';
    
    return 0;
}