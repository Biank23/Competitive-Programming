#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 101, MAX_X = 601;
 
double memo[MAX_X][MAX_N];
 
double dp(int x, int n) {
	if (x < n || x > 6*n) return 0.0;
	if (x == 0 && n == 0) return 1.0;
    double &res = memo[x][n];
	if (res != -1) return res;
	res = 0.0;
    for (int i = 1; i <= 6; i++) {
        res += dp(x - i, n - 1) / 6.0;
    }
	return res;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_N; j++) {
            memo[i][j] = -1;
        }
    }
    
	int n, a, b;
	cin >> n >> a >> b;
	
	double ans = 0.0;
    for (int i = a; i <= b; i++) {
        ans += dp(i, n);
    }
	
	cout << setprecision(6) << fixed << ans << '\n';
	
	return 0;
}
