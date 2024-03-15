#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ceilDiv(ll n, ll d) {
    return (n + d - 1) / d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll n, m, a;
    cin >> n >> m >> a;
    cout << ceilDiv(n, a) * ceilDiv(m, a) << '\n';
    
    return 0;
}
