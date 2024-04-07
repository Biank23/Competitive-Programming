#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("como.in", "r", stdin);
	freopen("como.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    x[0] = 0, cin >> y[0];
    for (int i = 1; i < n; i++) {
        cin >> y[i];
        x[i] = x[i - 1] + abs(y[i] - y[i - 1]);
    }
    int X;
    cin >> X;
    int i = 0;
    while (i < n && x[i] <= X) {
        i++;
    }
    assert(i > 0);
    if (i % 2 == 0) {
        cout << X << ' ' << y[i - 1] + X - x[i - 1] << '\n';
        return 0;
    }
    int Y = y[i - 1] + x[i - 1] - X;
    while (i + 1 < n && y[i + 1] < Y) {
        Y--;
        i += 2;
    }
    if (n % 2 == 1) Y--;
    cout << x[i] + Y - y[i] << ' ' << Y << '\n';
    
    return 0;
}
