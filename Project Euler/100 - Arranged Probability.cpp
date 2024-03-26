#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // x / y * (x - 1) / (y - 1) = 1 / 2
    // 2 * x * (x - 1) = y * (y - 1)
    // 2 * x^2 - 2 * x - y^2 + y = 0
    
    // https://www.alpertron.com.ar/QUAD.HTM
    // x_n+1 = 3 ⁢* x_n + 2 * ⁢(y_n - 1) ⁢
    // y_n+1 = 4 ⁢* x_n + 3 ⁢* (y_n - 1)
    
    const ll N = 1e12;
    
    ll x = 85;
    ll y = x + 35;
    while (y <= N) {
        tie(x, y) = make_pair(3 * x + 2 * (y - 1), // x
                              4 * x + 3 * (y - 1)); // y
    }
    cout << x << '\n';
    
    return 0;
}
