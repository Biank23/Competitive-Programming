#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("norusa.in", "r", stdin);
	freopen("norusa.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int X, Y;
    cin >> X >> Y;
    int i = 0;
    while (i < n && x[i] <= X) {
        i += 2;
    }
    int ans = 0;
    while (i < n && y[i] <= Y) {
        i += 2;
        ans++;
    }
    cout << ans << '\n';
    
    return 0;
}
