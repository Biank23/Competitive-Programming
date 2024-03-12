#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int TT;
	cin >> TT;
	for (int tt = 1 ; tt <= TT; tt++) {
		ll A, B, C;
        cin >> A >> B >> C;
        ll ans = 0;
        for (ll S : vector{0LL, 1LL, 2LL, C / A}) {
            if (C - A * S >= 0) {
                ll D = (C - A * S) / B;
                ll K = min(S + 2 * D, 2 * S + 2 * D - 1);
                ans = max(ans, K);
            }
        }
        cout << "Case #" << tt << ": " << ans << '\n';
	}
}
