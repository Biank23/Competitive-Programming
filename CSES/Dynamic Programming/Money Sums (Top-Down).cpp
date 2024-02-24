#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 100;
const int MAX_X = 1e5 + 9;
 
int memo[MAX_N][MAX_X], x[MAX_N];
 
bool dp(int i, int j) {
    if (j == 0) return true;
    if (j < 0 || i < 0) return false;
    if (memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = dp(i - 1, j) || dp(i - 1, j - x[i]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }
    memset(memo, -1, sizeof memo);
    
    vector<int> res;
    for (int i = 1; i <= sum; i++) {
        if (dp(n - 1, i)) res.push_back(i);
    }
    cout << ssize(res) << '\n';
    for (int &x : res) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}