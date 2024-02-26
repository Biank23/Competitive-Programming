#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
    double n, k;
    cin >> n >> k;
	
    double ans = 0.0;
    for (int i = 1; i <= k; i++) {
        ans += (pow(i / k, n) - pow((i - 1) / k, n)) * i;
    }
    cout << setprecision(6) << fixed << ans << '\n';
	
    return 0;
}
