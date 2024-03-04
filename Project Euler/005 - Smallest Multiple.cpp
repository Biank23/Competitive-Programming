#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { //euclides
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    // a * b = gcd(a, b) * lcm(a, b)
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 20;

    int res = 1;
    for (int i = 1; i <= N; i++) {
        res = lcm(res, i);
    }
    cout << res << '\n';

    return 0;
}